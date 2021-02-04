export module Ast;

import std.core;
import Datatype;

namespace ast {

export class Node;

export class ICal;

export class Component;
export class VCalendar;
export class VAlarm;
export class VEvent;
export class VJournal;

export class Property;
export class PropertyString;
export class PropertyDescription;
export class PropertyLocation;
export class PropertyUid;
export class PropertySummary;
export class PropertyMethod;
export class PropertyProdId;
export class PropertyVersion;
export class PropertyCalScale;
export class PropertyAttendee;

export class PropertyDate;
export class PropertyDtStart;
export class PropertyDtStamp;
export class PropertyDtEnd;
export class PropertyCreated;
export class PropertyLastModified;

export class PropertyInt;
export class PropertySequence;

export class NodeFactory;

export class Visitor;
export class XmlVisitor;
export class RoomOccupancyVisitor;

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

	const std::map<std::string, std::string>& get_params() const;

protected:
	std::map<std::string, std::string> params;
};

class PropertyString : public Property {
public:
	using sptr = std::shared_ptr<PropertyString>;
	using uptr = std::unique_ptr<PropertyString>;

	PropertyString(const std::string&, const std::map<std::string, std::string>&);
	virtual ~PropertyString() = default;

	const std::string& get_value() const;

private:
	std::string value;
};

class PropertyDescription : public PropertyString {
public:
	using sptr = std::shared_ptr<PropertyDescription>;
	using uptr = std::unique_ptr<PropertyDescription>;

	PropertyDescription(const std::string&, const std::map<std::string, std::string>&);
	virtual ~PropertyDescription() = default;

	void accept(std::shared_ptr<Visitor>) const override;
};

class PropertyLocation : public PropertyString {
public:
	using sptr = std::shared_ptr<PropertyLocation>;
	using uptr = std::unique_ptr<PropertyLocation>;

	PropertyLocation(const std::string&, const std::map<std::string, std::string>&);
	virtual ~PropertyLocation() = default;

	void accept(std::shared_ptr<Visitor>) const override;
};

class PropertyUid : public PropertyString {
public:
	using sptr = std::shared_ptr<PropertyUid>;
	using uptr = std::unique_ptr<PropertyUid>;

	PropertyUid(const std::string&, const std::map<std::string, std::string>&);
	virtual ~PropertyUid() = default;

	void accept(std::shared_ptr<Visitor>) const override;
};

class PropertySummary : public PropertyString {
public:
	using sptr = std::shared_ptr<PropertySummary>;
	using uptr = std::unique_ptr<PropertySummary>;

	PropertySummary(const std::string&, const std::map<std::string, std::string>&);
	virtual ~PropertySummary() = default;

	void accept(std::shared_ptr<Visitor>) const override;
};

class PropertyMethod : public PropertyString {
public:
	using sptr = std::shared_ptr<PropertyMethod>;
	using uptr = std::unique_ptr<PropertyMethod>;

	PropertyMethod(const std::string&, const std::map<std::string, std::string>&);
	virtual ~PropertyMethod() = default;

	void accept(std::shared_ptr<Visitor>) const override;
};

class PropertyProdId : public PropertyString {
public:
	using sptr = std::shared_ptr<PropertyProdId>;
	using uptr = std::unique_ptr<PropertyProdId>;

	PropertyProdId(const std::string&, const std::map<std::string, std::string>&);
	virtual ~PropertyProdId() = default;

	void accept(std::shared_ptr<Visitor>) const override;
};

class PropertyVersion : public PropertyString {
public:
	using sptr = std::shared_ptr<PropertyVersion>;
	using uptr = std::unique_ptr<PropertyVersion>;

	PropertyVersion(const std::string&, const std::map<std::string, std::string>&);
	virtual ~PropertyVersion() = default;

	void accept(std::shared_ptr<Visitor>) const override;
};

class PropertyCalScale : public PropertyString {
public:
	using sptr = std::shared_ptr<PropertyCalScale>;
	using uptr = std::unique_ptr<PropertyCalScale>;

	PropertyCalScale(const std::string&, const std::map<std::string, std::string>&);
	virtual ~PropertyCalScale() = default;

	void accept(std::shared_ptr<Visitor>) const override;
};

class PropertyAttendee : public PropertyString {
public:
	using sptr = std::shared_ptr<PropertyAttendee>;
	using uptr = std::unique_ptr<PropertyAttendee>;

	PropertyAttendee(const std::string&, const std::map<std::string, std::string>&);
	virtual ~PropertyAttendee() = default;

	void accept(std::shared_ptr<Visitor>) const override;
};

class PropertyDateTime : public Property {
public:
	using sptr = std::shared_ptr<PropertyDate>;
	using uptr = std::unique_ptr<PropertyDate>;

	PropertyDateTime(const datatype::DateTime&, const std::map<std::string, std::string>&);
	virtual ~PropertyDateTime() = default;

	const datatype::DateTime& get_value() const;

private:
	datatype::DateTime value;
};

class PropertyDtStart : public PropertyDateTime {
public:
	using sptr = std::shared_ptr<PropertyDtStart>;
	using uptr = std::unique_ptr<PropertyDtStart>;

	PropertyDtStart(const datatype::DateTime&, const std::map<std::string, std::string>&);
	virtual ~PropertyDtStart() = default;

	void accept(std::shared_ptr<Visitor>) const override;
};

class PropertyDtStamp : public PropertyDateTime {
public:
	using sptr = std::shared_ptr<PropertyDtStamp>;
	using uptr = std::unique_ptr<PropertyDtStamp>;

	PropertyDtStamp(const datatype::DateTime&, const std::map<std::string, std::string>&);
	virtual ~PropertyDtStamp() = default;

	void accept(std::shared_ptr<Visitor>) const override;
};

class PropertyDtEnd : public PropertyDateTime {
public:
	using sptr = std::shared_ptr<PropertyDtEnd>;
	using uptr = std::unique_ptr<PropertyDtEnd>;

	PropertyDtEnd(const datatype::DateTime&, const std::map<std::string, std::string>&);
	virtual ~PropertyDtEnd() = default;

	void accept(std::shared_ptr<Visitor>) const override;
};

class PropertyCreated : public PropertyDateTime {
public:
	using sptr = std::shared_ptr<PropertyCreated>;
	using uptr = std::unique_ptr<PropertyCreated>;

	PropertyCreated(const datatype::DateTime&, const std::map<std::string, std::string>&);
	virtual ~PropertyCreated() = default;

	void accept(std::shared_ptr<Visitor>) const override;
};

class PropertyLastModified : public PropertyDateTime {
public:
	using sptr = std::shared_ptr<PropertyLastModified>;
	using uptr = std::unique_ptr<PropertyLastModified>;

	PropertyLastModified(const datatype::DateTime&, const std::map<std::string, std::string>&);
	virtual ~PropertyLastModified() = default;

	void accept(std::shared_ptr<Visitor>) const override;
};

class PropertyInt : public Property {
public:
	using sptr = std::shared_ptr<PropertyInt>;
	using uptr = std::unique_ptr<PropertyInt>;

	PropertyInt(long long, const std::map<std::string, std::string>&);
	virtual ~PropertyInt() = default;

	long long get_value() const;

private:
	long long value;
};

class PropertySequence : public PropertyInt {
public:
	using sptr = std::shared_ptr<PropertySequence>;
	using uptr = std::unique_ptr<PropertySequence>;

	PropertySequence(long long, const std::map<std::string, std::string>&);
	virtual ~PropertySequence() = default;

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

	Property::uptr create_property(const std::string&, const std::string&, const std::map<std::string, std::string>&) const;
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
	virtual void visit_summary(const PropertySummary&) = 0;
	virtual void visit_location(const PropertyLocation&) = 0;
	virtual void visit_uid(const PropertyUid&) = 0;
	virtual void visit_method(const PropertyMethod&) = 0;
	virtual void visit_prod_id(const PropertyProdId&) = 0;
	virtual void visit_version(const PropertyVersion&) = 0;
	virtual void visit_cal_scale(const PropertyCalScale&) = 0;
	virtual void visit_attendee(const PropertyAttendee&) = 0;
	virtual void visit_dt_start(const PropertyDtStart&) = 0;
	virtual void visit_dt_stamp(const PropertyDtStamp&) = 0;
	virtual void visit_dt_end(const PropertyDtEnd&) = 0;
	virtual void visit_created(const PropertyCreated&) = 0;
	virtual void visit_last_modified(const PropertyLastModified&) = 0;
	virtual void visit_sequence(const PropertySequence&) = 0;
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

	void visit_property(const Property&);
	void visit_property_string(const std::string&, const PropertyString&);
	void visit_property_date_time(const std::string&, const PropertyDateTime&);
	void visit_property_int(const std::string&, const PropertyInt&);
	void visit_description(const PropertyDescription&) override;
	void visit_summary(const PropertySummary&) override;
	void visit_location(const PropertyLocation&) override;
	void visit_uid(const PropertyUid&) override;
	void visit_method(const PropertyMethod&) override;
	void visit_prod_id(const PropertyProdId&) override;
	void visit_version(const PropertyVersion&) override;
	void visit_cal_scale(const PropertyCalScale&) override;
	void visit_attendee(const PropertyAttendee&) override;
	void visit_dt_start(const PropertyDtStart&) override;
	void visit_dt_stamp(const PropertyDtStamp&) override;
	void visit_dt_end(const PropertyDtEnd&) override;
	void visit_created(const PropertyCreated&) override;
	void visit_last_modified(const PropertyLastModified&) override;
	void visit_sequence(const PropertySequence&) override;

private:
	std::ostream& out;
};

class RoomOccupancyVisitor : public Visitor {
public:
	RoomOccupancyVisitor(std::ostream&);
	virtual ~RoomOccupancyVisitor() = default;

	void visit_ical(const ICal&) override;

	void visit_component(const Component&);
	void visit_vcalendar(const VCalendar&) override;
	void visit_valarm(const VAlarm&) override;
	void visit_vevent(const VEvent&) override;
	void visit_vjournal(const VJournal&) override;

	void visit_property_string(const PropertyString&);
	void visit_property_date_time(const PropertyDateTime&);
	void visit_property_int(const PropertyInt&);
	void visit_description(const PropertyDescription&) override;
	void visit_summary(const PropertySummary&) override;
	void visit_location(const PropertyLocation&) override;
	void visit_uid(const PropertyUid&) override;
	void visit_method(const PropertyMethod&) override;
	void visit_prod_id(const PropertyProdId&) override;
	void visit_version(const PropertyVersion&) override;
	void visit_cal_scale(const PropertyCalScale&) override;
	void visit_attendee(const PropertyAttendee&) override;
	void visit_dt_start(const PropertyDtStart&) override;
	void visit_dt_stamp(const PropertyDtStamp&) override;
	void visit_dt_end(const PropertyDtEnd&) override;
	void visit_created(const PropertyCreated&) override;
	void visit_last_modified(const PropertyLastModified&) override;
	void visit_sequence(const PropertySequence&) override;

private:
	std::ostream& out;
	std::map<std::string, unsigned long> room_occupancy;
	std::vector<std::string> locations;
	std::optional<datatype::DateTime> start;
	std::optional<datatype::DateTime> end;
};

}
