#include "../include/datetimeLIB.hpp"

// Преобразовать в строку в формате "HH:mm:ss"
std::string DateTime::to_string(const time& t) {
	std::string result;
	int h = t.hour();
	int m = t.minute();
	int s = t.second();
	if (h < 10) {
		result += '0' + std::to_string(h) + ":";
	}
	else {
		result += std::to_string(h) + ":";
	}

	if (m < 10) {
		result += '0' + std::to_string(m) + ":";
	}
	else {
		result += std::to_string(m) + ":";
	}

	if (s < 10) {
		result += '0' + std::to_string(s);
	}
	else {
		result += std::to_string(s);
	}
	return result;
}

// Преобразовать в строку в формате "yyyy.MM.dd"
std::string DateTime::to_string(const date& d) {
	std::string result;
	int y = d.year();
	int m = d.month();
	int day_ = d.day();

	//Отловим возможные ошибки
	if (y > 0 && m > 0 && day_ == 0) {
		if (m - 1 > 0) {
			--m;
			day_ = DateTime::date::amount_in_month(m,DateTime::date::is_leapyear(y));
		}
		else {
			--y;
			m = 12;
			day_ = 31;
		}
	}


	if (y < 10) {
		result += "000" + std::to_string(y) + ".";
	}
	else if(y < 100){
		result += "00" + std::to_string(y) + ".";
	}
	else if (y < 1000) {
		result += "0" + std::to_string(y) + ".";
	}
	else {
		result += std::to_string(y) + ".";
	}

	if (m < 10) {
		result += '0' + std::to_string(m) + ".";
	}
	else {
		result += std::to_string(m) + ".";
	}

	if (day_ < 10) {
		result += '0' + std::to_string(day_);
	}
	else {
		result += std::to_string(day_);
	}
	
	return result;
}

// Преобразовать в строку в формате "yyyy.MM.dd HH:mm:ss"
std::string DateTime::to_string(const datetime& dt) {
	int y = dt.year();
	int m = dt.month();
	int day_ = dt.day();
	int h = dt.hour();
	int min = dt.minute();
	int s = dt.second();


	//Отловим возможные ошибки
	if (y > 0 && m > 0 && day_ == 0) {
		if (m - 1 > 0) {
			--m;
			day_ = DateTime::datetime::amount_in_month(m, DateTime::date::is_leapyear(y));
		}
		else {
			--y;
			m = 12;
			day_ = 31;
		}
	}


	std::string result;

	if (y < 10) {
		result += "000" + std::to_string(y) + ".";
	}
	else if (y < 100) {
		result += "00" + std::to_string(y) + ".";
	}
	else if (y < 1000) {
		result += "0" + std::to_string(y) + ".";
	}
	else {
		result += std::to_string(y) + ".";
	}

	if (m < 10) {
		result += '0' + std::to_string(m) + ".";
	}
	else {
		result += std::to_string(m) + ".";
	}

	if (day_ < 10) {
		result += '0' + std::to_string(day_);
	}
	else {
		result += std::to_string(day_);
	}

	result += ' ';

	if (h < 10) {
		result += '0' + std::to_string(h) + ":";
	}
	else {
		result += std::to_string(h) + ":";
	}

	if (min < 10) {
		result += '0' + std::to_string(min) + ":";
	}
	else {
		result += std::to_string(min) + ":";
	}

	if (s < 10) {
		result += '0' + std::to_string(s);
	}
	else {
		result += std::to_string(s);
	}

	return result;
}
