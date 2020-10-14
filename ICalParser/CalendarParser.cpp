module Parser;

import std.core;
import Ast;

namespace parser {

ast::Node::uptr CalendarParser::parse(std::istream& input) const
{
	ast::Node::uptr node = get_factory().create_node_calendar();
	std::string line;
	for (;;) {
		if (!std::getline(input, line)) {
			throw "Unexpected eof";
		}
		auto pos = line.find(":");
		if (pos == std::string::npos) {
			std::cerr << "':' not found, skipping line" << std::endl;
			continue;
		}
		std::string token1 = line.substr(0, pos);
		std::string token2 = line.substr(pos + 1);
		if (std::strcmp("END", token1.c_str()) == 0) {
			if (std::strcmp("VCALENDAR", token2.c_str()) != 0) {
				throw "Unexpected end: " + token2;
			}
			break;
		}
		if (std::strcmp("BEGIN", token1.c_str()) == 0) {
			// TODO
			std::cerr << "Skipping unknown component: " << token2 << std::endl;
			parse_unknown_component(input, token2.c_str());
		} else {
			// TODO
			std::cerr << "Skipping unknown property: " << token1 << std::endl;
		}
	}
	return node;
}

}
