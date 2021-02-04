module Ast;

import std.core;

namespace ast {

XmlVisitor::XmlVisitor(std::ostream& output)
	: out(output)
{
}

void XmlVisitor::visit_property(const Property& prop)
{
	for (auto param : prop.get_params()) {
		out << "<" << param.first << " value=\"" << param.second << "\"/>";
	}
}

void XmlVisitor::visit_ical(const ICal& ical)
{
	out << "<ICAL>";
	auto& calendars = ical.get_calendars();
	for (auto& calendar : calendars) {
		calendar->accept(shared_from_this());
	}
	out << "</ICAL>";
}

void XmlVisitor::visit_component(const Component& component)
{
	auto& props = component.get_properties();
	for (auto& prop : props) {
		prop->accept(shared_from_this());
	}
	auto& components = component.get_components();
	for (auto& component : components) {
		component->accept(shared_from_this());
	}
}

void XmlVisitor::visit_vcalendar(const VCalendar& vcal)
{
	out << "<VCALENDAR>";
	visit_component(vcal);
	out << "</VCALENDAR>";
}

void XmlVisitor::visit_valarm(const VAlarm& valarm)
{
	out << "<VALARM>";
	visit_component(valarm);
	out << "</VALARM>";
}

void XmlVisitor::visit_vevent(const VEvent& vevent)
{
	out << "<VEVENT>";
	visit_component(vevent);
	out << "</VEVENT>";
}

void XmlVisitor::visit_vjournal(const VJournal& vjournal)
{
	out << "<VJOURNAL>";
	visit_component(vjournal);
	out << "</VJOURNAL>";
}

void XmlVisitor::visit_property_string(const std::string& name, const PropertyString& prop)
{
	out << "<" << name << " value=\"" << prop.get_value() << "\">";
	visit_property(prop);
	out << "</" << name << ">";
}

void XmlVisitor::visit_description(const PropertyDescription& prop)
{
	visit_property_string("DESCRIPTION", prop);
}

void XmlVisitor::visit_summary(const PropertySummary& prop)
{
	visit_property_string("SUMMARY", prop);
}

void XmlVisitor::visit_location(const PropertyLocation& prop)
{
	visit_property_string("LOCATION", prop);
}

void XmlVisitor::visit_uid(const PropertyUid& prop)
{
	visit_property_string("UID", prop);
}

void XmlVisitor::visit_method(const PropertyMethod& prop)
{
	visit_property_string("METHOD", prop);
}

void XmlVisitor::visit_prod_id(const PropertyProdId& prop)
{
	visit_property_string("PRODID", prop);
}

void XmlVisitor::visit_version(const PropertyVersion& prop)
{
	visit_property_string("VERSION", prop);
}

void XmlVisitor::visit_cal_scale(const PropertyCalScale& prop)
{
	visit_property_string("CALSCALE", prop);
}

void XmlVisitor::visit_attendee(const PropertyAttendee& prop)
{
	visit_property_string("ATTENDEE", prop);
}

void XmlVisitor::visit_property_date_time(const std::string& name, const PropertyDateTime& prop)
{
	// TODO
	out << "<" << name << " value=\"" << prop.get_value() << "\">";
	visit_property(prop);
	out << "</" << name << ">";
}

void XmlVisitor::visit_dt_start(const PropertyDtStart& prop)
{
	visit_property_date_time("DTSTART", prop);
}

void XmlVisitor::visit_dt_stamp(const PropertyDtStamp& prop)
{
	visit_property_date_time("DTSTAMP", prop);
}

void XmlVisitor::visit_created(const PropertyCreated& prop)
{
	visit_property_date_time("CREATED", prop);
}

void XmlVisitor::visit_last_modified(const PropertyLastModified& prop)
{
	visit_property_date_time("LAST-MODIFIED", prop);
}

void XmlVisitor::visit_dt_end(const PropertyDtEnd& prop)
{
	visit_property_date_time("DTEND", prop);
}

void XmlVisitor::visit_property_int(const std::string& name, const PropertyInt& prop)
{
	out << "<" << name <<" value=\"" << prop.get_value() << "\">";
	visit_property(prop);
	out << "</" << name << ">";
}

void XmlVisitor::visit_sequence(const PropertySequence& prop)
{
	visit_property_int("SEQUENCE", prop);
}

}
