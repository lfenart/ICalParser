export module Ast;

import std.core;

namespace ast {

export class Node;
export class ICal;
export class VCalendar;
export class VEvent;
export class VAlarm;
export class Component;
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

class Component : public Node {
public:
	using sptr = std::shared_ptr<Component>;
	using uptr = std::unique_ptr<Component>;

	virtual ~Component() = default;

	const std::vector<Component::uptr>& get_components() const;
	void add_component(Component::uptr);

private:
	std::vector<Component::uptr> components;
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
	VCalendar::uptr create_vcalendar() const;
	ICal::uptr create_ical() const;
	VEvent::uptr create_vevent() const;
	VAlarm::uptr create_valarm() const;
};

class Visitor : public std::enable_shared_from_this<Visitor> {
public:
	virtual ~Visitor() = default;

	virtual void visit_ical(const ICal&) = 0;
	virtual void visit_vcalendar(const VCalendar&) = 0;
	virtual void visit_valarm(const VAlarm&) = 0;
	virtual void visit_vevent(const VEvent&) = 0;
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

private:
	std::ostream& out;
};

}
