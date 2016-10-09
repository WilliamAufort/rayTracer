#include <iostream>
#include <cstdlib>
#include "../include/parserArguments.hpp"

using namespace std;

parserArguments::parserArguments(vector<string> nomsOptions, vector<string> nomsParameters) :
    arguments(vector<string>()), options(map<string, bool>()), parameters(map<string, string>())
{
    for (string option : nomsOptions)
        options[option] = false;

    for (string param : nomsParameters)
        parameters[param] = "";

    options["h"] = false;
    options["-help"] = false;
}

bool parserArguments::askHelp()
{
    return options["h"] || options["-help"];
}

size_t parserArguments::nbArguments() const
{
	return arguments.size();
}

void parserArguments::parse(int argc, char* argv[])
{
    unsigned int nbArgs = 0;
    for (int i = 1; i < argc; i++)
    {
        if (argv[i][0] == '-')
        {
            string option = string(argv[i]).substr(1);
            if (option.find("=") == string::npos)
            {
                if (options.count(option) == 0)
                    cerr << "Unknown option : " << option << endl;
                else
                options[option] = true;

            }
            else
            {
                if (parameters.count(option.substr(0,option.find("="))) == 0)
                    cerr << "Unknown parameter : " << option.substr(0,option.find("=")) << endl;
                else
                    parameters[option.substr(0,option.find("="))] = option.substr(option.find("=")+1);
        }   }
        else
        {
            arguments.push_back(argv[i]);
            nbArgs++;
}   }   }

string parserArguments::getArgument(size_t index) const
{
    return arguments[index];
}

bool parserArguments::getOption(string nom) const
{
    return options.at(nom);
}

string parserArguments::getParameter(string nom) const
{
    return parameters.at(nom);
}

string parserArguments::getParameter(string nom, string def) const
{
    if (parameters.count(nom) == 0)
        return def;
    if (parameters.at(nom) == "")
        return def;
    return parameters.at(nom);
}

vector<string> parserArguments::getOptionsNames()
{
    vector<string> liste(14);
    liste[0] = "-gamma";
    return liste;
}

vector<string> parserArguments::getParametersNames()
{
    vector<string> liste(1);
    liste[0] = "-output";
    return liste;
}
