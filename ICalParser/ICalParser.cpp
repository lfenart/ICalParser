module Parser;

import std.core;
import Exception;

namespace parser {

ast::Node::uptr ICalParser::parse(std::istream& input) const
{
	ast::ICal::uptr node = get_factory().create_ical();
	std::string line;
	for (;;) {
		auto prop = read_tokens(input);
		if (!prop.has_value()) {
			break;
		}
		std::string token1 = prop->get_name();
		std::string token2 = prop->get_value();
		if (token1 != "BEGIN" || token2 != "VCALENDAR") {
			throw std::runtime_error("BEGIN:VCALENDAR not found");
		}
		ast::Node::uptr calendar = calendar_parser.parse(input);
		node->add_calendar(ast::VCalendar::uptr(dynamic_cast<ast::VCalendar*>(calendar.release())));
	}
	return node;
}

}
