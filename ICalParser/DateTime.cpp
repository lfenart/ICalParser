module Datatype;

import std.core;

namespace datatype {

DateTime::DateTime(const std::string& val)
{
	//_putenv("TZ=");
	auto pos = val.find("T");
	// todo check npos
	std::string date = val.substr(0, pos);
	std::string time = val.substr(pos + 1);
	int year = std::stoi(date.substr(0, 4));
	int month = std::stoi(date.substr(4, 2));
	int day = std::stoi(date.substr(6, 2));
	int hour = std::stoi(time.substr(0, 2));
	int minute = std::stoi(time.substr(2, 2));
	int second = std::stoi(time.substr(4, 2));
	// todo fuseau horaire
	std::tm tm = { second, minute, hour, day, month - 1, year - 1900 };
	date_time = _mktime64(&tm);
}

unsigned long DateTime::duration(const DateTime& start) const
{
	return (unsigned long)_difftime64(date_time, start.date_time);
}

std::ostream& DateTime::print_on(std::ostream& out) const
{
	char buff[30];
	struct tm tm = { 0, 0, 0, 1, 0, 70 };
	if (date_time >= 0) {
		_localtime64_s(&tm, &date_time);
	}
	strftime(buff, sizeof(buff), "%Y%m%dT%H%M%SZ", &tm);
	return out << buff;
}

std::ostream& operator<<(std::ostream& out, const DateTime& DateTime)
{
	return DateTime.print_on(out);
}

}
