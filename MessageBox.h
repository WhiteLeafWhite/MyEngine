#pragma once
#include <set>
#include <mutex>
#include "E_Message.h"
class EMessageBox
{
private:
	std::set<E_Message> _message_box;
	std::set<E_Message> _buffer;
	static EMessageBox* messageBox;
	static std::mutex mb_mutex;
	EMessageBox() {};
	EMessageBox(const EMessageBox& mb) = delete;
	EMessageBox operator = (const EMessageBox& mb) = delete;

public:
	static EMessageBox* get_instance();
	bool put_message(E_Message e_m);
	bool has_message(std::string expect_content);
	void clear_message();
	std::set<E_Message>& get_box();
};