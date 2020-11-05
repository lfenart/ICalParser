module Parser;

import std.core;
import Exception;

namespace parser {

const ast::NodeFactory& Parser::get_factory() const
{
	return factory;
}

std::optional<std::pair<std::string, std::string>> Parser::read_tokens(std::istream& input) const
{
	std::string line;
	if (!std::getline(input, line)) {
		return std::nullopt;
	}
	int c = input.get();
	while (c == ' ' || c == '\t') {
		std::string next_line;
		std::getline(input, next_line);
		line += next_line;
		c = input.get();
	}
	input.unget();
	auto pos = line.find(":");
	if (pos == std::string::npos) {
		throw exception::MissingColonError();
	}
	std::string token1 = line.substr(0, pos);
	std::string token2 = line.substr(pos + 1);
	return std::pair<std::string, std::string>(token1, token2);
}

void Parser::parse_unknown_component(std::istream& input, const std::string& name) const
{
	for (;;) {
		auto tokens = read_tokens(input);
		if (!tokens.has_value()) {
			throw exception::UnexpectedEofError();
		}
		std::string token1 = tokens->first;
		std::string token2 = tokens->second;
		if (token1 == "END") {
			if (token2 != name) {
				throw exception::UnexpectedComponentEndError(token2);
			}
			return;
		}
		if (token1 == "BEGIN") {
			parse_unknown_component(input, token2);
		}
	}
}

}
