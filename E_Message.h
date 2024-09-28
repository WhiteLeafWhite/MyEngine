#pragma once
#include<string>
class E_Message
{
private:
	int sender_id;
	std::string content;
public:
	E_Message(int ss, std::string cc);
	E_Message();
	int get_sender_id();
	std::string get_content();
	void set(int sid, std::string cc);
	bool operator <(const E_Message& other) const{
		if (sender_id == other.sender_id&&content.length()==other.content.length()) {
			std::string t = other.content;
			for (int i = 0; i < content.length(); ++i) {
				if (content[i] == t[i]) continue;
				else return content[i] < t[i];
			}
		}
		else if (sender_id == other.sender_id) {
			return content.length() < other.content.length();
		}
		return sender_id < other.sender_id;
	}
	bool operator ==(const E_Message& other) const {
		return sender_id == other.sender_id && content == other.content;
	}
};

