#include "E_Message.h"

E_Message::E_Message(int ss, std::string cc)
{
	sender_id = ss;
	content = cc;
}

E_Message::E_Message()
{
	sender_id = -1;
	content = "";
}

int E_Message::get_sender_id()
{
	return sender_id;
}

std::string E_Message::get_content()
{
	return content;
}

void E_Message::set(int sid, std::string cc)
{
	sender_id = sid;
	content = cc;
}
