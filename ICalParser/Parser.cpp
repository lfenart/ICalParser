module Parser;

import std.core;
import Exception;

namespace parser {

const ast::NodeFactory& Parser::get_factory() const
{
	return factory;
}

void Parser::parse_unknown_component(std::istream& input, const std::string& name) const
{
	for (;;) {
		std::string line;
		if (!std::getline(input, line)) {
			throw exception::UnexpectedEofError();
		}
		auto pos = line.find(":");
		if (pos == std::string::npos) {
			std::cerr << "':' not found, skipping line" << std::endl;
		} else {
			std::string token1 = line.substr(0, pos);
			std::string token2 = line.substr(pos + 1);
			if (token1 == "END") {
				if (token2 == name) {
					return;
				} else {
					throw "unexpected end";
				}
			}
			if (token1 == "BEGIN") {
				parse_unknown_component(input, token2);
			}
		}
	}
}

}
