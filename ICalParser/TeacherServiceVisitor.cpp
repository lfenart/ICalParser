module Ast;

import std.core;
import std.regex;

namespace ast {

TeacherServiceVisitor::TeacherServiceVisitor(std::ostream& output)
	: out(output), teacher_subjects()
{
}

void TeacherServiceVisitor::visit_ical(const ICal& ical)
{
	auto& calendars = ical.get_calendars();
	for (auto& calendar : calendars) {
		calendar->accept(shared_from_this());
	}
	for (auto it : teacher_subjects) {
		std::cout << it.first << std::endl;
		for (auto subject : it.second) {
			std::cout << "\t" << subject << std::endl;
		}
	}


	/*std::vector<std::pair<std::string, unsigned long>> sorted;
	for (auto it : room_occupancy) {
		sorted.push_back(it);
	}
	std::sort(sorted.begin(), sorted.end(), [](const std::pair<std::string, unsigned long>& a, const std::pair<std::string, unsigned long>& b) -> bool {
		return a.second > b.second;
	});
	for (auto it : sorted) {
		std::cout << it.first << " => " << it.second / (36 * 36 * 36.0) << "%" << std::endl;
	}*/
}

void TeacherServiceVisitor::visit_component(const Component& component)
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

void TeacherServiceVisitor::visit_vcalendar(const VCalendar& vcal)
{
	visit_component(vcal);
}

void TeacherServiceVisitor::visit_valarm(const VAlarm& valarm)
{
	visit_component(valarm);
}

void TeacherServiceVisitor::visit_vevent(const VEvent& vevent)
{
	visit_component(vevent);
	if (!teachers.empty() && subject.has_value()) {
		for (auto teacher : teachers) {
			teacher_subjects[teacher].insert(*subject);
		}
	}
	teachers.clear();
	subject = {};
}

void TeacherServiceVisitor::visit_vjournal(const VJournal& vjournal)
{
}

void TeacherServiceVisitor::visit_property_string(const PropertyString& prop)
{
}

void TeacherServiceVisitor::visit_description(const PropertyDescription& prop)
{
	std::regex re(R"((\\n[^0-9]*)*\\n\(Export)",
		std::regex_constants::ECMAScript);
	std::smatch matchs;
	std::regex_search(prop.get_value(), matchs, re);
	std::string raw = matchs[1];
	if (raw.size() < 2) {
		return;
	}
	raw = raw.substr(2);
	while (true) {
		auto pos = raw.find("\\n");
		if (pos == std::string::npos) {
			return;
		}
		teachers.push_back(raw.substr(0, pos));
		raw = raw.substr(pos + 2);
	}
}

void TeacherServiceVisitor::visit_summary(const PropertySummary& prop)
{
	subject = prop.get_value();
}

void TeacherServiceVisitor::visit_location(const PropertyLocation& prop)
{
}

void TeacherServiceVisitor::visit_uid(const PropertyUid& prop)
{
}

void TeacherServiceVisitor::visit_method(const PropertyMethod& prop)
{
}

void TeacherServiceVisitor::visit_prod_id(const PropertyProdId& prop)
{
}

void TeacherServiceVisitor::visit_version(const PropertyVersion& prop)
{
}

void TeacherServiceVisitor::visit_cal_scale(const PropertyCalScale& prop)
{
}

void TeacherServiceVisitor::visit_attendee(const PropertyAttendee& prop)
{
}

void TeacherServiceVisitor::visit_property_date_time(const PropertyDateTime& prop)
{
}

void TeacherServiceVisitor::visit_dt_start(const PropertyDtStart& prop)
{
}

void TeacherServiceVisitor::visit_dt_stamp(const PropertyDtStamp& prop)
{
}

void TeacherServiceVisitor::visit_created(const PropertyCreated& prop)
{
}

void TeacherServiceVisitor::visit_last_modified(const PropertyLastModified& prop)
{
}

void TeacherServiceVisitor::visit_dt_end(const PropertyDtEnd& prop)
{
}

void TeacherServiceVisitor::visit_property_int(const PropertyInt& prop)
{
}

void TeacherServiceVisitor::visit_sequence(const PropertySequence& prop)
{
}

}
