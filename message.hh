namespace mess {

	template <class Stream>
	void message(Stream & stream, const char* string)
	{
		stream << string;
	}

	template <class Stream, class Arg, class ... Args>
	void message(Stream & stream, const char* string, Arg const & arg, Args const &... args)
	{
		const char * i = string;
		for (;; i++)
		{
			if (*i != '%')
				stream << *i;
			else {
				i++;
				break;
			};
			if (*i == '\0')
				return;
		}
		stream << arg;
		message(stream, i, args...);
	}
}
