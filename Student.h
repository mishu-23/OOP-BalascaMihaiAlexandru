class Student {
	char* name;
	int Maths, English, History;

public:
	void setName(char *nume[]);
	char* getName();
	bool setMaths(int x);
	int getMaths();
	bool setEnglish(int x);
	int getEnglish();
	bool setHistory(int x);
	int getHistory();
	int getAverage();
};