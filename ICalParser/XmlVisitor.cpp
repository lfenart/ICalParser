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
	auto& children = component.get_components();
	for (auto& child : children) {
		child->accept(shared_from_this());
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

}
