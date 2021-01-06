module Ast;

import std.core;

namespace ast {

XmlVisitor::XmlVisitor(std::ostream& output)
	: out(output)
{
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

void XmlVisitor::visit_property_string(const PropertyString& prop)
{
	out << " value=\"" << prop.get_value() << "\"/>";
}

void XmlVisitor::visit_description(const PropertyDescription& prop)
{
	out << "<DESCRIPTION";
	visit_property_string(prop);
}

void XmlVisitor::visit_summary(const PropertySummary& prop)
{
	out << "<SUMMARY";
	visit_property_string(prop);
}

void XmlVisitor::visit_location(const PropertyLocation& prop)
{
	out << "<LOCATION";
	visit_property_string(prop);
}

void XmlVisitor::visit_uid(const PropertyUid& prop)
{
	out << "<UID";
	visit_property_string(prop);
}

void XmlVisitor::visit_method(const PropertyMethod& prop)
{
	out << "<METHOD";
	visit_property_string(prop);
}

void XmlVisitor::visit_prod_id(const PropertyProdId& prop)
{
	out << "<PRODID";
	visit_property_string(prop);
}

void XmlVisitor::visit_version(const PropertyVersion& prop)
{
	out << "<VERSION";
	visit_property_string(prop);
}

void XmlVisitor::visit_cal_scale(const PropertyCalScale& prop)
{
	out << "<CALSCALE";
	visit_property_string(prop);
}

void XmlVisitor::visit_property_date_time(const PropertyDateTime& prop)
{
	// TODO
	out << " value=\"" << prop.get_value() << "\"/>";
}

void XmlVisitor::visit_dt_start(const PropertyDtStart& prop)
{
	out << "<DTSTART";
	visit_property_date_time(prop);
}

void XmlVisitor::visit_dt_stamp(const PropertyDtStamp& prop)
{
	out << "<DTSTAMP";
	visit_property_date_time(prop);
}

void XmlVisitor::visit_created(const PropertyCreated& prop)
{
	out << "<CREATED";
	visit_property_date_time(prop);
}

void XmlVisitor::visit_last_modified(const PropertyLastModified& prop)
{
	out << "<LAST-MODIFIED";
	visit_property_date_time(prop);
}

void XmlVisitor::visit_dt_end(const PropertyDtEnd& prop)
{
	out << "<DTEND";
	visit_property_date_time(prop);
}

void XmlVisitor::visit_property_int(const PropertyInt& prop)
{
	out << " value=\"" << prop.get_value() << "\"/>";
}

void XmlVisitor::visit_sequence(const PropertySequence& prop)
{
	out << "<SEQUENCE";
	visit_property_int(prop);
}

}
