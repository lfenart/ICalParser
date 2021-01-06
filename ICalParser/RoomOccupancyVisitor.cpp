module Ast;

import std.core;

namespace ast {

RoomOccupancyVisitor::RoomOccupancyVisitor(std::ostream& output)
	: out(output)
	, room_occupancy()
{
}

void RoomOccupancyVisitor::visit_ical(const ICal& ical)
{
	auto& calendars = ical.get_calendars();
	for (auto& calendar : calendars) {
		calendar->accept(shared_from_this());
	}
	std::vector<std::pair<std::string, unsigned long>> sorted;
	for (auto it : room_occupancy) {
		sorted.push_back(it);
	}
	std::sort(sorted.begin(), sorted.end(), [](const std::pair<std::string, unsigned long>& a, const std::pair<std::string, unsigned long>& b) -> bool {
		return a.second > b.second;
	});
	for (auto it : sorted) {
		std::cout << it.first << " => " << it.second / (36 * 36 * 36.0) << "%" << std::endl;
	}
}

void RoomOccupancyVisitor::visit_component(const Component& component)
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

void RoomOccupancyVisitor::visit_vcalendar(const VCalendar& vcal)
{
	visit_component(vcal);
}

void RoomOccupancyVisitor::visit_valarm(const VAlarm& valarm)
{
	visit_component(valarm);
}

void RoomOccupancyVisitor::visit_vevent(const VEvent& vevent)
{
	visit_component(vevent);
	if (!locations.empty() && start.has_value() && end.has_value()) {
		for (auto location : locations) {
			room_occupancy[location] += end->duration(*start);
			//std::cout << end->duration(*start) * 1.0 / 3600 << std::endl;
		}
	}
	locations.clear();
	start = {};
	end = {};
}

void RoomOccupancyVisitor::visit_vjournal(const VJournal& vjournal)
{
}

void RoomOccupancyVisitor::visit_property_string(const PropertyString& prop)
{
}

void RoomOccupancyVisitor::visit_description(const PropertyDescription& prop)
{
}

void RoomOccupancyVisitor::visit_summary(const PropertySummary& prop)
{
}

void RoomOccupancyVisitor::visit_location(const PropertyLocation& prop)
{
	std::string location = prop.get_value();
	auto pos = location.find("\\,");
	while (pos != std::string::npos) {
		locations.push_back(location.substr(0, pos));
		location = location.substr(pos + 2);
		pos = location.find("\\,");
	}
	locations.push_back(location);
	//std::cout << *location << std::endl;
}

void RoomOccupancyVisitor::visit_uid(const PropertyUid& prop)
{
}

void RoomOccupancyVisitor::visit_method(const PropertyMethod& prop)
{
}

void RoomOccupancyVisitor::visit_prod_id(const PropertyProdId& prop)
{
}

void RoomOccupancyVisitor::visit_version(const PropertyVersion& prop)
{
}

void RoomOccupancyVisitor::visit_cal_scale(const PropertyCalScale& prop)
{
}

void RoomOccupancyVisitor::visit_property_date_time(const PropertyDateTime& prop)
{
}

void RoomOccupancyVisitor::visit_dt_start(const PropertyDtStart& prop)
{
	start = prop.get_value();
	//std::cout << *start << std::endl;
}

void RoomOccupancyVisitor::visit_dt_stamp(const PropertyDtStamp& prop)
{
}

void RoomOccupancyVisitor::visit_created(const PropertyCreated& prop)
{
}

void RoomOccupancyVisitor::visit_last_modified(const PropertyLastModified& prop)
{
}

void RoomOccupancyVisitor::visit_dt_end(const PropertyDtEnd& prop)
{
	end = prop.get_value();
	//std::cout << *end << std::endl;
}

void RoomOccupancyVisitor::visit_property_int(const PropertyInt& prop)
{
}

void RoomOccupancyVisitor::visit_sequence(const PropertySequence& prop)
{
}

}
