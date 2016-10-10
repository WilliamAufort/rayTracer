#ifndef DEF_PARSERARGUMENTS
#define DEF_PARSERARGUMENTS

#include<string>
#include<vector>
#include<map>

// TODO More english

class parserArguments
{
	public:
		parserArguments(std::vector<std::string> nomsOptions, std::vector<std::string> nomsParameters);
		~parserArguments(){};
		bool askHelp();

		size_t nbArguments() const __attribute__((pure));
		void parse(int argc, char* argv[]);

		std::string getArgument(size_t index) const;
		bool getOption(std::string nom) const;
		std::string getParameter(std::string nom) const;
		std::string getParameter(std::string nom, std::string def) const;

		static std::vector<std::string> getOptionsNames();
		static std::vector<std::string> getParametersNames();

	private:
		std::vector<std::string> arguments;
		std::map<std::string, bool> options;
		std::map<std::string, std::string> parameters;
};

#endif
