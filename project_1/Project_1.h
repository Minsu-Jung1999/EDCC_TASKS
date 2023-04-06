#ifndef ADD_H
#define ADD_H

enum EMode
{
	CREATE_MODE = 1,
	VIEW_MODE,
	QUIT,
	EMODE_MAX
};

bool FindingFile(std::string input_file_name_);
void GameStartText();
int ModeSetting();
void CreateFile();
void ViewFile();
void AskingQuestions(std::string file_contents);

//string Replace(string replaced_words);




#endif