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
	out << " value=\"" << prop.get_value() << "\"\\>";
}

void XmlVisitor::visit_description(const PropertyDescription& description)
{
	out << "<DESCRIPTION";
	visit_property_string(description);
}

void XmlVisitor::visit_property_date(const PropertyDate& prop)
{
	// TODO
	out << " value=\"" << prop.get_value() << "\"\\>";
}

void XmlVisitor::visit_dt_start(const PropertyDtStart& description)
{
	out << "<DTSTART";
	visit_property_date(description);
}

}
