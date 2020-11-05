export module Ast;

import std.core;

namespace ast {

export class Node;
export class ICal;
export class VCalendar;
export class VEvent;
export class VAlarm;
export class VJournal;
export class Component;
export class Property;
export class PropertyString;
export class PropertyDescription;
export class NodeFactory;
export class Visitor;
export class XmlVisitor;

class Node {
public:
	using sptr = std::shared_ptr<Node>;
	using uptr = std::unique_ptr<Node>;

	virtual ~Node() = default;

	virtual void accept(std::shared_ptr<Visitor>) const = 0;
};

class Property : public Node {
public:
	using sptr = std::shared_ptr<Property>;
	using uptr = std::unique_ptr<Property>;

	virtual ~Property() = default;
};

class PropertyString : public Property {
public:
	using sptr = std::shared_ptr<PropertyString>;
	using uptr = std::unique_ptr<PropertyString>;

	PropertyString(const std::string&);
	virtual ~PropertyString() = default;

	const std::string& get_value() const;

private:
	std::string value;
};

class PropertyDescription : public PropertyString {
public:
	using sptr = std::shared_ptr<PropertyString>;
	using uptr = std::unique_ptr<PropertyString>;

	PropertyDescription(const std::string&);
	virtual ~PropertyDescription() = default;

	void accept(std::shared_ptr<Visitor>) const override;
};

class Component : public Node {
public:
	using sptr = std::shared_ptr<Component>;
	using uptr = std::unique_ptr<Component>;

	virtual ~Component() = default;

	const std::vector<Component::uptr>& get_components() const;
	void add_component(Component::uptr);

	const std::vector<Property::uptr>& get_properties() const;
	void add_property(Property::uptr);

private:
	std::vector<Component::uptr> components;
	std::vector<Property::uptr> properties;
};

class VCalendar : public Component {
public:
	using sptr = std::shared_ptr<VCalendar>;
	using uptr = std::unique_ptr<VCalendar>;

	VCalendar() = default;
	virtual ~VCalendar() = default;

	void accept(std::shared_ptr<Visitor>) const override;
};

class VEvent : public Component {
public:
	using sptr = std::shared_ptr<VEvent>;
	using uptr = std::unique_ptr<VEvent>;

	VEvent() = default;
	virtual ~VEvent() = default;

	void accept(std::shared_ptr<Visitor>) const override;
};

class VAlarm : public Component {
public:
	using sptr = std::shared_ptr<VAlarm>;
	using uptr = std::unique_ptr<VAlarm>;

	VAlarm() = default;
	virtual ~VAlarm() = default;

	void accept(std::shared_ptr<Visitor>) const override;
};

class VJournal : public Component {
public:
	using sptr = std::shared_ptr<VJournal>;
	using uptr = std::unique_ptr<VJournal>;

	VJournal() = default;
	virtual ~VJournal() = default;

	void accept(std::shared_ptr<Visitor>) const override;
};

class ICal : public Node {
public:
	using sptr = std::shared_ptr<ICal>;
	using uptr = std::unique_ptr<ICal>;

	ICal() = default;
	virtual ~ICal() = default;

	const std::vector<VCalendar::uptr>& get_calendars() const;
	void add_calendar(VCalendar::uptr);

	void accept(std::shared_ptr<Visitor>) const override;

private:
	std::vector<VCalendar::uptr> calendars;
};

class NodeFactory {
public:
	ICal::uptr create_ical() const;
	VCalendar::uptr create_vcalendar() const;
	VAlarm::uptr create_valarm() const;
	VEvent::uptr create_vevent() const;
	VJournal::uptr create_vjournal() const;

	Property::uptr create_property(const std::string&, const std::string&) const;
};

class Visitor : public std::enable_shared_from_this<Visitor> {
public:
	virtual ~Visitor() = default;

	virtual void visit_ical(const ICal&) = 0;
	virtual void visit_vcalendar(const VCalendar&) = 0;
	virtual void visit_valarm(const VAlarm&) = 0;
	virtual void visit_vevent(const VEvent&) = 0;
	virtual void visit_vjournal(const VJournal&) = 0;

	virtual void visit_description(const PropertyDescription&) = 0;
};

class XmlVisitor : public Visitor {
public:
	XmlVisitor(std::ostream&);
	virtual ~XmlVisitor() = default;

	void visit_ical(const ICal&) override;

	void visit_component(const Component&);
	void visit_vcalendar(const VCalendar&) override;
	void visit_valarm(const VAlarm&) override;
	void visit_vevent(const VEvent&) override;
	void visit_vjournal(const VJournal&) override;

	void visit_property_string(const PropertyString&);
	void visit_description(const PropertyDescription&) override;

private:
	std::ostream& out;
};

}
