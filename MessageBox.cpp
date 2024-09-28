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

//�������������һ����Ϣ
bool EMessageBox::put_message(E_Message e_m)
{
	_buffer.insert(e_m);
	return true;
}

//�����û������Ҫ����Ϣ���Ҿ���������᳣��
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

//ֱ�Ӱ����������ù���
std::set<E_Message>& EMessageBox::get_box()
{
	return _message_box;
}