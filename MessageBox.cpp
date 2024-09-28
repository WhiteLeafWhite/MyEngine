#include "MessageBox.h"

std::mutex EMessageBox::mb_mutex;
EMessageBox* EMessageBox::messageBox = nullptr;

EMessageBox* EMessageBox::get_instance()
{
	if (messageBox == nullptr) {
		std::lock_guard<std::mutex> m(mb_mutex);
		if (messageBox == nullptr) {
			messageBox = new EMessageBox();
		}
	}
	return messageBox;
}

//向信箱里面添加一条消息
bool EMessageBox::put_message(E_Message e_m)
{
	_buffer.insert(e_m);
	return true;
}

//检测有没有我想要的信息，我觉得这个不会常用
bool EMessageBox::has_message(std::string expect_content)
{
	for (E_Message message : _message_box) {
		if (message.get_content() == expect_content) return true;
	}
	return false;
}

void EMessageBox::clear_message()
{
	_message_box.clear();
	for (E_Message message : _buffer) {
		_message_box.insert(message);
	}
	_buffer.clear();
}

//直接把整个信箱拿过来
std::set<E_Message>& EMessageBox::get_box()
{
	return _message_box;
}