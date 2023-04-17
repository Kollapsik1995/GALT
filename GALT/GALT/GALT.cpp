#include <stdlib.h>
#include <string>
#include <iostream>
#include <functional>
#include <map>
#include <vector>
#include <fstream>

void help(std::string s), diff(std::string s), getcharachter(std::string s), setcharachter(std::string s),strmul(std::string s), conc(std::string s), eqw(std::string s), andf(std::string s), orf(std::string s), xorf(std::string s), neq(std::string s), bgt(std::string s), smt(std::string s), info(std::string s), gotree(std::string s), execpart(std::string s), range(std::string s), randm(std::string s), read(std::string s), fexit(std::string s), version(std::string s), dict(std::string s), itself(std::string s), _var(std::string s), sel(std::string s), put(std::string s), wrt(std::string s),addvar(std::string s), getvar(std::string s), IF(std::string s), WHILE(std::string s), FOR(std::string s),fadd(std::string s), fsub(std::string s), fmul(std::string s), fdivd(std::string s), add(std::string s), sub(std::string s), mul(std::string s), divd(std::string s), mod(std::string s), sys(std::string s), nw(std::string s), execute(std::string s), pack(std::string s);
void split(std::string str, char del);
std::string _itself="";
std::string _;
std::string now;
std::map<std::string, std::string> vars;
std::map<std::string, std::function<void(std::string)>> words;
std::map<std::string, std::string> listwords;
std::vector<std::string> tempbuf;

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "");
	
	words["-help"] = *help;
	words["-info"] = *info;
	words["-ver"] = *version;
	words["-words"] = *dict;
	words["_itself"] = *itself;
	words["wrt"] = *wrt;
	words["avr"] = *addvar;
	words["gvr"] = *getvar;
	words["add"] = *add;
	words["sub"] = *sub;
	words["mul"] = *mul;
	words["div"] = *divd;
	words["fadd"] = *fadd;
	words["fsub"] = *fsub;
	words["fmul"] = *fmul;
	words["fdiv"] = *fdivd;
	words["mod"] = *mod;
	words["?"] = *IF;
	words["@"] = *WHILE;
	words[">"] = *FOR;
	words["_"] = *_var;
	words["sys"] = *sys;
	words["rd"] = *read;
	words["exit"] = *fexit;
	words["nw"] = *nw;
	words["rnd"] = *randm;
	words["eqw"] = *eqw;
	words["neq"] = *neq;
	words["bgt"] = *bgt;
	words["smt"] = *smt;
	words["and"] = *andf;
	words["or"] = *orf;
	words["xor"] = *xorf;
	words["sel"] = *sel;
	words["smul"] = *strmul;
	words["diff"] = *diff;
	words["con"] = *conc;
	words["rng"] = *range;
	words["gtc"] = *getcharachter;
	words["stc"] = *setcharachter;
	/*
	words["put"] = *put;
	words["time"] = *time;
	words["wrtf"] = *writefile;
	words["rdf"] = *readfile;
	*/
	if (argc == 1) {
		system("echo Hello %username%!\n");
		std::cout << "Welcome to GALT Shell!\nif you don't know what exactly to do, just type -help\n\n" << std::endl;
		std::string input;
		while (true) {
			std::cout << "$run: ";
			getline(std::cin, input);
			try {
					if (input.find(' ') != std::string::npos) {
							words[input.substr(0, input.find(' '))](input.substr(input.find(' ') + 1, input.size() - (input.find(' ') + 1)));
					}
					else {
							words[input]("");
					}
					
			}
			catch (std::bad_function_call ex) {
				std::cout << "where do you take that? put in the place!" << std::endl;
				std::cout << input.substr(0, input.find(' ')) << " ~~~ " << input.substr(input.find(' ') + 1, input.size() - (input.find(' ') + 1)) << std::endl;
			}
			tempbuf.clear();
		}
	}
	else if (argc == 2) {
		if (argv[1] == "-help") {
			help("");
			return 0;
		}
		else if (argv[1] == "-info") {
			info("");
			return 0;
		}
		else if (argv[1] == "-ver") {
			version("");
			return 0;
		}
		else if (argv[1] == "-words") {}
		else {
			std::string input = argv[1];
			words[input.substr(0, input.find(' '))](input.substr(input.find(' ') + 1, input.size() - (input.find(' ') + 1)));
		}
	}
}

void help(std::string s) {
	_itself = "";
	std::cout<<"well, listen\nyou can write any useful program in that interpreter, because it's turing full\nBUT! you must know, that it will be not as easy as on, you know, some C++, or Assembly...\n get Ready!\n\n\n type:\n  -help for help\n  -info for information about this awful language and something else...\n  -ver to know version of this :P\n  -words to learn commands\n  -pack for compile your code into *.glt\n\n\n good luck!\n\n"<< std::endl;
}

void info(std::string s) {
	_itself = "";
	std::cout << "Are you really interested in??\nWell, this language was made in one night by mad one on 24.03.2023 in Russia (I'm not joking!)\nidea was taken from such programming languages as FORTH, RED, Brainfuck, hq9+ and Assemby, so...\nit was cool night, baby!\nif you read this and you are not me, or friend of mine, that means that you are very bored that time...\nGALT was written on C++ in Visual Studio 2022... at period of time when microsoft gone from Russia... Qt and Tik-Tok do the same, but i'am tiktoker, and qt-developer...\nsorry for that monologue, I don't have a lot of friends to talk :~)\nbest wishes\nNikolai\nTeacher)\n\n\n\nNow seriously: you can call word by it name, or make new word by typing\n\n  nw WORD:ANY|WORDS|YOU|WANT\n\nyou can use \"(\" and \")\" to group words in complex:\n\n  nw WORD:(ANY(OTHER WORDS))YOU|WANT\n\nthat's all!\n\nenjoy!" << std::endl;
}

void version(std::string s) {
	_itself = "0.1";
	std::cout << "  ver 0.1 - \"Lemon Toad\"" << std::endl;
}

void read(std::string s) {
	getline(std::cin, _itself);
}

void range(std::string s) {
	std::string rng = "";
	split(s, ' ');
	for (int i = atoi(vars[tempbuf[0]].c_str()); i < atoi(vars[tempbuf[1]].c_str()); i += atoi(vars[tempbuf[2]].c_str())) {
		rng += std::to_string(i);
		if (i < atoi(vars[tempbuf[1]].c_str()) - 1) {
			rng += ",";
		}
	}
	_itself = rng;
}

void getcharachter(std::string s){
	split(s, ' ');
	_itself = "";
	_itself	+= vars[tempbuf[0]].at(atoi(vars[tempbuf[1]].c_str()));
}
void setcharachter(std::string s){
	split(s, ' ');
	vars[tempbuf[0]].replace((atoi(vars[tempbuf[1]].c_str())),1,1,_itself.c_str()[0]);
}


void eqw(std::string s) {
	split(s, ' ');
	if (vars[tempbuf[0]] == vars[tempbuf[1]]) { _itself = "TRU"; }
	else { _itself = "FLS"; }
}
void neq(std::string s) {
	split(s, ' ');
	if (vars[tempbuf[0]] != vars[tempbuf[1]]) { _itself = "TRU"; }
	else { _itself = "FLS"; }
}
void bgt(std::string s) {
	split(s, ' ');
	if (atof(vars[tempbuf[0]].c_str()) > atof(vars[tempbuf[1]].c_str())) { _itself = "TRU"; }
	else { _itself = "FLS"; }
}
void smt(std::string s) {
	split(s, ' ');
	if (atof(vars[tempbuf[0]].c_str()) < atof(vars[tempbuf[1]].c_str())) { _itself = "TRU"; }
	else { _itself = "FLS"; }
}
void andf(std::string s) {
	split(s, ' ');
	if (vars[tempbuf[0]] == "TRU" && vars[tempbuf[1]] == "TRU") { _itself = "TRU"; }
	else { _itself = "FLS"; }
}
void orf(std::string s) {
	split(s, ' ');
	if (vars[tempbuf[0]] == "TRU" || vars[tempbuf[1]] == "TRU") { _itself = "TRU"; }
	else { _itself = "FLS"; }
}
void xorf(std::string s) {
	split(s, ' ');
	if (vars[tempbuf[0]] == "TRU" && vars[tempbuf[1]] == "FLS" || vars[tempbuf[0]] == "FLS" && vars[tempbuf[1]] == "TRU") { _itself = "TRU"; }
	else { _itself = "FLS"; }
}
void notf(std::string s) {
	if (vars[tempbuf[atoi(s.c_str())]] == "FLS") { _itself = "TRU"; }
	else { _itself = "FLS"; }
}

void randm(std::string s) {
	if (s == "") {
		_itself = std::to_string(rand());
	}
	else {
		_itself = std::to_string(rand() % atoi(vars[s].c_str()));
	}
}
void fexit(std::string s) {
	exit(0);
}

void itself(std::string s) {
	if (s == "") {
		_itself = _itself;
	}
	else{
		_itself = s;
	}
}

void _var(std::string s) {
	_itself = _;
}

void wrt(std::string s) {
	if (s == "_itself" || s == "") {
		std::cout << _itself;
	}
	else if (s == "nl") {
		std::cout << std::endl;
	}
	else {
		std::cout << s;
	}
}


void addvar(std::string s) {
	std::string varname, varval;
	if (s.find(' ') != std::string::npos) {
		varname = s.substr(0, s.find(' '));
		varval = s.substr(s.find(' ') + 1, s.size() - (s.find(' ') + 1));
	}
	else {
		varname = s;
		varval = "";
	}
	if (varval == "") {
		varval = _itself;
	}
	vars[varname] = varval;
}

void diff(std::string s) {
	split(s, ' ');
	std::string arr1 = vars[tempbuf[0]];
	std::string arr2 = vars[tempbuf[1]];
	std::string arr3 = "";
	split(arr1, ',');
	auto tempbuf2 = tempbuf;
	split(arr2, ',');
	bool include = true;
	for (std::string el : tempbuf) {
		for (std::string el2 : tempbuf2) {
			if (el == el2) {
				include = false;
			}
		}
		if (include) {
			if (arr3 != "") {
				arr3 += ',';
			}
			arr3 += el;
		}
	}
	_itself = arr3;
}

void strmul(std::string s) {
	split(s, ' ');
	std::string outstr = "";
	for (int i = 0; i < atoi(vars[tempbuf[1]].c_str()); i++) {
		outstr += vars[tempbuf[0]];
	}
	_itself = outstr;
}

void getvar(std::string s) {
	_itself = vars[s];
}

void IF(std::string s) {
	if (!(_itself == "" || _itself == "0" || _itself == "FLS")) {
			execute(s);
	}
}

void WHILE(std::string s) {
	std::string temp_itself = _itself;
	while (!(_itself == "" || _itself == "0" || _itself == "FLS")) {
				execute(s);
	}
	_itself = temp_itself;
}

void FOR(std::string s) {
	split(_itself, ',');
	std::string temp_itself = _itself;
	auto tempb = tempbuf;
	for(std::string e : tempb) {
		_ = e;
		_var("");
		execute(s);
	}
	_itself = temp_itself;
}

void add(std::string s) {
	split(s,' ');
	_itself = std::to_string(atoi(vars[tempbuf[0]].c_str()) + atoi(vars[tempbuf[1]].c_str()));
}

void sub(std::string s) {
	split(s, ' ');
	_itself = std::to_string(atoi(vars[tempbuf[0]].c_str()) - atoi(vars[tempbuf[1]].c_str()));
}

void mul(std::string s) {
	split(s, ' ');
	_itself = std::to_string(atoi(vars[tempbuf[0]].c_str()) * atoi(vars[tempbuf[1]].c_str()));
}

void divd(std::string s) {
	split(s, ' ');
	_itself = std::to_string(atoi(vars[tempbuf[0]].c_str()) / atoi(vars[tempbuf[1]].c_str()));
}

void mod(std::string s) {
	split(s, ' ');
	_itself = std::to_string(atoi(vars[tempbuf[0]].c_str()) % atoi(vars[tempbuf[1]].c_str()));
}

void fadd(std::string s) {
	split(s, ' ');
	_itself = std::to_string(atof(vars[tempbuf[0]].c_str()) + atof(vars[tempbuf[1]].c_str()));
}

void fsub(std::string s) {
	split(s, ' ');
	_itself = std::to_string(atof(vars[tempbuf[0]].c_str()) - atof(vars[tempbuf[1]].c_str()));
}

void fmul(std::string s) {
	split(s, ' ');
	_itself = std::to_string(atof(vars[tempbuf[0]].c_str()) * atof(vars[tempbuf[1]].c_str()));
}

void fdivd(std::string s) {
	split(s, ' ');
	_itself = std::to_string(atof(vars[tempbuf[0]].c_str()) / atof(vars[tempbuf[1]].c_str()));
}

void sys(std::string s) {
	system(s.c_str());
}

void nw(std::string s) {
	words[s.substr(0, s.find(':'))] = [s](std::string x) {execute(s.substr(s.find(':') + 1, s.size() - (s.find(':') + 1))); };
}

void dict(std::string s) {}

void sel(std::string s) {

}

void put(std::string s) {
	
}

void conc(std::string s) {
	split(s, ' ');
	_itself = vars[tempbuf[0]] + vars[tempbuf[0]];
}

void execute(std::string s) {
	execpart(s);
}

void execpart(std::string s) {
	gotree(s);
	split(s, '|');
	auto tempb = tempbuf;
	for (std::string e : tempb) {
		if (e.find(' ') != std::string::npos) {
			words[e.substr(0, e.find(' '))](e.substr(e.find(' ') + 1, e.size() - (e.find(' ') + 1)));
		}
		else {
			words[e]("");
		}
	}
}

void gotree(std::string s) {
	int num = 0;
	int charnum = 0;
	int char2num = 0;
	int ind = 0;
	for (char sign : s) {
		if (sign == '[') {
			if (num == 0) {
				charnum = ind;
			}
			num++;
		}

		if (sign == ']') {
			num--;
			if (num == 0) {
				char2num = ind;
				execpart(s.substr(charnum+1,char2num-charnum-1));
			}
		}

		ind++;
	}
}




void split(std::string str, char del) {
	std::string temp = "";
	tempbuf.clear();
	for (int i = 0; i < (int)str.size(); i++) {
		if (str[i] != del) {
			temp += str[i];
		}
		else {
			tempbuf.push_back(temp);
			temp = "";
		}
	}
	tempbuf.push_back(temp);
}