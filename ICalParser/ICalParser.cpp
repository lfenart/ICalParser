module Parser;

import std.core;
import Exception;

namespace parser {

ast::Node::uptr ICalParser::parse(std::istream& input) const
{
	ast::ICal::uptr node = get_factory().create_node_ical();
	std::string line;
	while (std::getline(input, line)) {
		auto pos = line.find(":");
		if (pos == std::string::npos) {
			throw exception::MissingColonError();
		}
		std::string token1 = line.substr(0, pos);
		std::string token2 = line.substr(pos + 1);
		if (std::strcmp("BEGIN", token1.c_str()) != 0 || std::strcmp("VCALENDAR", token2.c_str()) != 0) {
			throw std::runtime_error("BEGIN::VCALENDAR not found");
		}
		ast::Node::uptr calendar = calendar_parser.parse(input);
		node->add_calendar(ast::VCalendar::uptr(dynamic_cast<ast::VCalendar*>(calendar.release())));
	}
	return node;
}

}
