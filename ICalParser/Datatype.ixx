export module Datatype;

import std.core;

namespace datatype {

export class Date;

class Date {
public:
	Date(const std::string&);
	virtual ~Date() = default;

	std::ostream& print_on(std::ostream&) const;

	friend std::ostream& operator<<(std::ostream&, const Date&);

private:
	// TODO
	std::string value;
};

}
