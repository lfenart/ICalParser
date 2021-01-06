export module Datatype;

import std.core;

namespace datatype {

export class DateTime;

class DateTime {
public:
	DateTime(const std::string&);
	virtual ~DateTime() = default;

	unsigned long duration(const DateTime&) const;

	std::ostream& print_on(std::ostream&) const;

	friend std::ostream& operator<<(std::ostream&, const DateTime&);

private:
	std::time_t date_time;
};

}
