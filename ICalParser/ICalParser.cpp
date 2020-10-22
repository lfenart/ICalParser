module Parser;

import std.core;
import Exception;

namespace parser {

ast::Node::uptr ICalParser::parse(std::istream& input) const
{
	ast::ICal::uptr node = get_factory().create_ical();
	std::string line;
	for (;;) {
		auto tokens = read_tokens(input);
		if (!tokens.has_value()) {
			break;
		}
		std::string token1 = tokens->first;
		std::string token2 = tokens->second;
		if (token1 != "BEGIN" || token2 != "VCALENDAR") {
			throw std::runtime_error("BEGIN::VCALENDAR not found");
		}
		ast::Node::uptr calendar = calendar_parser.parse(input);
		node->add_calendar(ast::VCalendar::uptr(dynamic_cast<ast::VCalendar*>(calendar.release())));
	}
	return node;
}

}
