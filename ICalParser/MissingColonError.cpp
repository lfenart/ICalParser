module Exception;

import std.core;

namespace exception {

MissingColonError::MissingColonError()
	: std::runtime_error("Missing colon")
{
}

}
