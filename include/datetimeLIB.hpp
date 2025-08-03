#include <exception>
#include <string>
#include <stdexcept>


namespace DateTime {

	enum class weekday { sunday, monday, tuesday, wednesday, thursday, friday, saturday };

	class time;
	class date;
	class datetime;
	class timediff;


	class timediff {
	private:
		int seconds_;
	public:

		timediff(int days_, int hours_, int minutes_, int seconds_) {
			//Проверка значений конструктора
			if (hours_ > 23 || hours_ < -23) {
				throw std::invalid_argument("hours must be between -23 and 23 (timeDiff)");
			}
			if (minutes_ > 59 || minutes_ < -59) {
				throw std::invalid_argument("minute must be between -59 and 59 (timeDiff)");
			}
			if (seconds_ > 59 || seconds_ < -59) {
				throw std::invalid_argument("second must be between -59 and 59 (timeDiff)");
			}

			if ((days_ <= 0 && hours_ <= 0 && minutes_ <= 0 && seconds_ <= 0) || (days_ >= 0 && hours_ >= 0 && minutes_ >= 0 && seconds_ >= 0) ) {
				this->seconds_ = (days_ * 86400 + hours_ * 3600 + minutes_* 60 + seconds_);
			}
			else {
				throw std::invalid_argument("parametrs must be same sign (timeDiff)");
			}
		}

		timediff(int seconds_) {
			this->seconds_ = seconds_;
		}


		long long days() const {            // Получить количество дней
			return (static_cast<long long>(seconds_) / 86400);
		}

		long long  hours() const {           // Получить количество часов
			return (static_cast<long long>(seconds_) - (static_cast<long long>(seconds_) / 86400) * 86400) / 3600;
		}

		long long minutes() const {         // Получить количество минут   
			long long sec_day = (static_cast<long long>(seconds_) / 86400) * 86400;
			long long sec_hour = ((static_cast<long long>(seconds_) - sec_day) / 3600) * 3600;
			return (seconds_ - sec_day - sec_hour) / 60;
		}

		long long seconds() const {         // Получить количество секунд
			return (seconds_ % 60);
		}

		long long total_hours() const {     // Получить общее количество часов (с учётом количества дней)
			return seconds_ / 3600;
		}

		long long total_minutes() const {   // Получить общее количество минут
			return seconds_ / 60;
		}

		int total_seconds() const {   // Получить общее количество секунд
			return seconds_;
		}


		//--------------------- ОПИШЕМ ОПЕРАТОРЫ ---------------------------
		bool operator==(const timediff& d) const {
			return seconds_ == d.seconds_;
		}

		bool operator!=(const timediff& d) const {
			return seconds_ != d.seconds_;
		}

		bool operator<(const timediff& d) const {
			return seconds_ < d.seconds_;
		}

		bool operator<=(const timediff& d) const {
			return seconds_ <= d.seconds_;
		}

		bool operator>(const timediff& d) const {
			return seconds_ > d.seconds_;
		}

		bool operator>=(const timediff& d) const {
			return seconds_ >= d.seconds_;
		}

		timediff operator-(const timediff& d) const {
			return timediff((seconds_ - d.seconds_));
		}

		timediff operator+(const timediff& d) const {
			return timediff((seconds_ + d.seconds_));
		}


	};
	



	class time {
	private:
		int second_;
	public:

		time(int hour_, int minute_, int second_) {
			//Проверка значений конструктора
			if (hour_ > 23 || hour_ < 0) {
				throw std::invalid_argument("hours must be between 0 and 23 (time)");
			}
			if (minute_ > 59 || minute_ < 0) {
				throw std::invalid_argument("minute must be between 0 and 59 (time)");
			}
			if (second_ > 59 || second_ < 0) {
				throw std::invalid_argument("second must be between 0 and 59 (time)");
			}

			this->second_ = hour_*3600 + minute_ * 60 + second_;

		}

		time();

		time(int second) {
			this->second_ = second;
		}



		int all_second() const {
			return second_;
		}

		//Опишем геттеры
		int hour() const { // Получить количество часов
			return (second_/3600);
		}
		int minute() const { // Получить количество минут
			return ((second_ - ((second_ / 3600) * 3600)) / 60);
		}
		int second() const { // Получить количество секунд
			return (second_% 60);
		}


		void add_hours(int nb_hours) {  // Добавить заданное количество часов
			second_ += nb_hours*3600;
			if (second_ > 86399) {
				second_ = 86399;
			}
			if (second_ < 0) {
				second_ = 0;
			}
		}

		void add_minutes(int nb_minutes) {  // Добавить заданное количество минут
			second_ += nb_minutes*60;
			if (second_ > 86399) {
				second_ = 86399;
			}
			if (second_ < 0) {
				second_ = 0;
			}
		}

		void add_seconds(int nb_seconds) {  // Добавить заданное количество секунд
			second_ += nb_seconds;
			if (second_ > 86399) {
				second_ = 86399;
			}
			if (second_ < 0) {
				second_ = 0;
			}
		}




		void add_hours_new(int nb_hours) {  // Добавить заданное количество часов новая версия
			second_ += nb_hours * 3600;
			if (second_ > 86399 || second_ < 0) {
				second_ = 0;
			}
		}

		void add_minutes_new(int nb_minutes) {  // Добавить заданное количество минут новая версия
			second_ += nb_minutes * 60;
			if (second_ > 86399 || second_ < 0) {
				second_ = 0;
			}
		}

		void add_seconds_new(int nb_seconds) {  // Добавить заданное количество секунд новая версия
			second_ += nb_seconds;
			if (second_ > 86399 || second_ < 0) {
				second_ = 0;
			}
		}





		//--------------------- ОПИШЕМ ОПЕРАТОРЫ ---------------------------
		bool operator==(const time& t) const {
			return second_ == t.second_;
		}

		bool operator!=(const time& t) const {
			return second_ != t.second_;
		}


		bool operator<(const time& t) const {
			return second_ < t.second_;
		}


		bool operator<=(const time& t) const {
			return second_ <= t.second_;
		}


		bool operator>(const time& t) const {
			return second_ > t.second_;
		}


		bool operator>=(const time& t) const {
			return second_ >= t.second_;
		}


		timediff operator-(const time& t) const {
			int secDiff = (second_ - t.second_);
			return timediff(0, secDiff/3600 , (secDiff - ( (secDiff/3600) * 3600) )/60, secDiff%60); 
		}



	};




	class date {
	private:
		int day_;

		static int convertToJD(int Year, int Month, int Day) {
			int a = (14 - Month) / 12;
			int y = Year + 4800 - a;
			int m = Month + 12 * a - 3;
			return (Day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045);
		}


		int getA() const {
			return day_ + 32044;
		}

		int getB() const{
			int a = getA();
			return (4 * a + 3) / 146097;
		}

		int getC() const{
			int a = getA();
			int b = getB();
			return a - (146097 * b) / 4;
		}

		int getD() const{
			int c = getC();
			return (4 * c + 3) / 1461;
		}

		int getE() const{
			int c = getC();
			int d = getD();
			return c - 1461 * d / 4;
		}

		int getM() const{
			int e = getE();
			return (5 * e + 2) / 153;
		}



	public:
		date(int year_, int month_, int day_) { //При неправильном задании аргументов конструктора бросать исключение std::invalid_argument.
			//Проверка значений конструктора
			if (year_ > 9999 || year_ < 1) {
				throw std::invalid_argument("year must be between 1 and 9999 (date)");
			}
			if (month_ > 12 || month_ < 1) {
				throw std::invalid_argument("month must be between 1 and 12 (date)");
			}
			if (day_ > DateTime::date::amount_in_month(month_,date::is_leapyear(year_)) || day_ < 1) {
				throw std::invalid_argument("day must be between 1 and 31 (date)"); 
			}

			this->day_ = DateTime::date::convertToJD(year_,month_,day_);
		}

		date();

		date(int day) {
			this->day_ = day;
		}

		//Опишем геттеры
		int year() const {  // Получить год   
			return 100 * getB() + getD() - 4800 + getM() / 10;
		}


		int month() const { // Получить месяц
			return getM() + 3 - 12 * (getM() / 10);
		}


		int day() const {   // Получить день
			return getE() - (153 * getM() + 2) / 5 + 1;

		}


		int get_total_day() const {
			return day_;
		}



		DateTime::weekday weekday() const {   // Получить день недели для даты
			int y = year();
			int m = month();
			int d = day(); 

			if (m < 3) {
				y -= 1;  // Январь и февраль относим к предыдущему году
				m += 12;
			}

			int k = y % 100;  // Год в столетии
			int j = y / 100;  // Век

			int h = (d + (13 * (m + 1)) / 5 + k + (k / 4) + (j / 4) - (2 * j)) % 7;

			switch (h) {
			case 0: return weekday::saturday;
			case 1: return weekday::sunday;
			case 2: return weekday::monday;
			case 3: return weekday::tuesday;
			case 4: return weekday::wednesday;
			case 5: return weekday::thursday;
			case 6: return weekday::friday;
			}
			return weekday::sunday;
		}

		static int amount_in_month(int n,bool is_leap)  {
			if (n > 0 && n < 13) {
				if (is_leap) {
					int arr[] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
					return arr[n - 1];
				}
				int arr[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
				return arr[n - 1];
			}
			return -1;
		}

		bool is_leapyear() const {    // true, если год високосностный, иначе false
			int y = year();
			return ((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0);
		}

		void add_days(int nb_days) { // Добавить заданное количество дней
			day_ += nb_days;
		}

		date next() const {           // Получить дату для следующего дня
			date copy = (*this);
			++copy.day_;
			return copy;
		}

		date prev() const {			  // Получить дату для предыдущего дня
			date copy = (*this);
			--copy.day_;
			return copy;
		}

		static bool is_leapyear(int year) { // Проверка года на високосность 
			return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		}


		//--------------------- ОПИШЕМ ОПЕРАТОРЫ ---------------------------
		bool operator==(const date& d) const {
			return day_ == d.day_;
		}


		bool operator!=(const date& d) const{
			return day_ != d.day_;
		}
		

		bool operator<(const date& d) const {
			return day_ < d.day_;
		}


		bool operator<=(const date& d) const {
			return day_ <= d.day_;
		}


		bool operator>(const date& d) const {
			return day_ > d.day_;
		}

		bool operator>=(const date& d) const {
			return day_ >= d.day_;
		}
		
		timediff operator-(const date& d) const {
			return timediff((day_ - d.day_), 0, 0, 0);
		}

		//В префиксном инкременте мы сперва увеличиваем значение, затем возвращаем этот же объект
		date& operator++() {
			++day_;
			return (*this);
		}
		//Постфиксный инкремент
		/*
		В постфиксном инкременте (Объект++) мы сначала сохраняем текущее состояние объекта, а затем увеличиваем его.
		Так как нам нужно вернуть старое значение, мы создаём копию объекта, а не изменённую версию самого объекта.
		int - это фиктивный параметр, который используется только для различения префиксной (++Объект) и постфиксной (Объект++) форм
		*/
		date operator++(int) {
			date copy = (*this);
			++day_;
			return copy;
		}

		date& operator--() {
			--day_;
			return (*this);
		}

		date operator--(int) {
			date copy = (*this);
			--day_;
			return copy;
		}

	};




	class datetime {
	private:
		date d;
		time t;
	public:

		datetime(int year_, int month_, int day_, int hour_ = 0, int minute_ = 0, int second_ = 0) : d(year_, month_, day_), t(hour_, minute_, second_) {
			if (year_ > 9999 || year_ < 1) {
				throw std::invalid_argument("year must be between 1 and 9999 (date)");
			}
			if (month_ > 12 || month_ < 1) {
				throw std::invalid_argument("month must be between 1 and 12 (date)");
			}
			if (day_ > DateTime::datetime::amount_in_month(month_,datetime::is_leapyear(year_)) || day_ < 1) {
				throw std::invalid_argument("day must be between 1 and 31 (date)");
			}
			if (hour_ > 23 || hour_ < 0) {
				throw std::invalid_argument("hours must be between 0 and 23 (time)");
			}
			if (minute_ > 59 || minute_ < 0) {
				throw std::invalid_argument("minute must be between 0 and 59 (time)");
			}
			if (second_ > 59 || second_ < 0) {
				throw std::invalid_argument("second must be between 0 and 59 (time)");
			}
			
		}


		datetime(const date& dt, const time& tm) { 
			this->d = dt;
			this->t = tm;
		}

		datetime(int date_, int time_) : d(date_), t(time_) {}
			


		//Опишем геттеры
		date getDate() const{
			return d;
		}

		time getTime() const{
			return t;
		}




		int year() const {
			return d.year();
		}


		int month() const {
			return d.month();
		}


		int day() const {
			return d.day();
		}


		int hour() const {
			return t.hour();
		}


		int minute() const {
			return t.minute();
		}
		

		int second() const {
			return t.second();
		}











		static int amount_in_month(int n, bool is_leap) {
			if (n > 0 && n < 13) {
				if (is_leap) {
					int arr[] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
					return arr[n - 1];
				}
				int arr[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
				return arr[n - 1];
			}
			return -1;
		}


		DateTime::weekday weekday() const {
			int localYear = (year() - ((14 - month()) / 12));
			int localMonth = month() + 12 * ((14 - month()) / 12) - 2;
			int locDay = (day() + localYear + localYear / 4 - (localYear / 100) + (localYear / 400) + ((31 * localMonth) / 12)) % 7;
			switch (locDay) {
			case 0: return weekday::sunday;
			case 1: return weekday::monday;
			case 2: return weekday::tuesday;
			case 3: return weekday::wednesday;
			case 4: return weekday::thursday;
			case 5: return weekday::friday;
			case 6: return weekday::saturday;
			}
			return weekday::sunday;
		}

		bool is_leapyear() const {          // true, если год високосностный, иначе false
			int y = year();
			return ((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0);
		}

		

		void add_days(int nb_days){		   // Добавить заданное количество дней
			d.add_days(nb_days);
		}
		
		void add_hours(int nb_hours) {      // Добавить заданное количество часов
			bool isAddingDay = false;
			if (t.hour() + nb_hours > 23) {
				while (t.hour() + nb_hours > 23) {
					d.add_days(1);
					isAddingDay = true;
					nb_hours -= 24;
				}
			}

			if (nb_hours == 0 && isAddingDay) {
				nb_hours = 1;
			}
			t.add_hours_new(nb_hours);
		}


			
		void add_minutes(int nb_minutes) {  // Добавить заданное количество минут
			if (t.minute() + nb_minutes > 59) {
				int count_hour = 0;
				bool isAddingDay = false;
				while (t.minute() + nb_minutes > 59) {
					++count_hour; 
					nb_minutes -= 60;
				}
				while (count_hour + t.hour() > 23) {
					count_hour -= 24;
					d.add_days(1);
					isAddingDay = true;
				}
				if (count_hour == 0 && isAddingDay) {
					count_hour = 1;
				}
				t.add_hours_new(count_hour);
			}
			else if (t.minute() + nb_minutes < 0) {
				int count_hour = 0;
				while (t.minute() + nb_minutes < 0) {
					--count_hour;
					nb_minutes += 60;
				}
				while (count_hour + t.hour() < 0) {
					d.add_days(-1);
					count_hour += 24;
				}
				t.add_hours_new(count_hour);
			}
			t.add_minutes(nb_minutes);
		}


		void add_seconds(int nb_seconds) {  // Добавить заданное количество секунд
			if (t.second() + nb_seconds > 59) {
				int count_minute = 0;
				int count_hour = 0;
				bool isAddingMinute = false;
				bool isAddingHour = false;
				bool isAddingDay = false;
				while (t.second() + nb_seconds > 59) {
					++count_minute;
					isAddingMinute = true;
					nb_seconds -= 60;
				}
				while (count_minute + t.minute() > 59) {
					++count_hour;
					isAddingHour = true;
					count_minute -= 60;
				}
				while (count_hour + t.hour() > 23) {
					count_hour -= 24;
					d.add_days(1);
					isAddingDay = true;
				}
				if (count_hour == 0 && isAddingDay) {
					count_hour = 1;
				}
				if (count_minute == 0 && isAddingHour) {
					count_minute = 1;
				}
				if (nb_seconds == 0 && isAddingMinute) {
					nb_seconds = 1;
				}
				t.add_hours_new(count_hour);
				t.add_minutes_new(count_minute);

			}
			else if (t.second() + nb_seconds < 0) {
				int count_minute = 0;
				int count_hour = 0;
				while (t.second() + nb_seconds < 0) {
					--count_minute;
					nb_seconds += 60;
				}
				while (count_minute + t.minute() < 0) {
					--count_hour;
					count_minute += 60;
				}
				while (count_hour + t.minute() < 0) {
					count_hour += 24;
					d.add_days(-1);
				}
				t.add_hours_new(count_hour);
				t.add_minutes_new(count_minute);
			}

			t.add_seconds(nb_seconds);
		}

		static bool is_leapyear(int year) { // Проверка года на високосность 
			return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		}


		//--------------------- ОПИШЕМ ОПЕРАТОРЫ ---------------------------
		bool operator==(const datetime& d_) const {
			return (t == d_.getTime() && d == d_.getDate());
		}

		bool operator!=(const datetime& d_) const {
			return (t != d_.getTime() || d != d_.getDate());
		}

		bool operator<(const datetime& d_) const {
			if (d < d_.getDate()) {
				return true;
			}
			if (d == d_.getDate()) {
				return t < d_.getTime();
			}
			return false;
		}

		bool operator<=(const datetime& d_) const {
			if (d <= d_.getDate()) {
				return true;
			}
			if (d == d_.getDate()) {
				return t <= d_.getTime();
			}
			return false;
		}

		bool operator>(const datetime& d_) const {
			if (d > d_.getDate()) {
				return true;
			}
			if (d == d_.getDate()) {
				return t > d_.getTime();
			}
			return false;
		}

		bool operator>=(const datetime& d_) const {
			if (d >= d_.getDate()) {
				return true;
			}
			if (d == d_.getDate()) {
				return t >= d_.getTime();
			}
			return false;
		}



		timediff operator-(const datetime& d_) const {
			int difference_d = d.get_total_day() - d_.getDate().get_total_day();
			int difference_t = (t.hour() * 3600 + t.minute() * 60 + t.second()) - (d_.getTime().hour() * 3600 + d_.getTime().minute() * 60 + d_.getTime().second());
			if (difference_t < 0) {
				difference_t = 86400  + difference_t % 86400;
				difference_d -= 1;
			}
			return timediff(difference_t + difference_d * 86400);
		}

		
		datetime operator-(const timediff& td) const {
			int difference_d = d.get_total_day();
			int difference_t = (t.hour() * 3600 + t.minute() * 60 + t.second()) - td.total_seconds();
			if (difference_t < 0) {
				int ds = difference_t / 86400;
				difference_t = 86400 + difference_t % 86400;
				difference_d += ds - 1;
			}
			return datetime(difference_d,difference_t);
		}


		datetime operator+(const timediff& td) const {
			int difference_t = (t.second() + t.minute() * 60 + t.hour() * 3600) + td.total_seconds();
			int difference_d = d.get_total_day();
			if (difference_t > 86399) {
				int df = difference_t / 86400;
				difference_t = difference_t % 86400;
				difference_d += df;
			}
			return datetime(difference_d, difference_t);
		}



	};



	// Преобразовать в строку в формате "HH:mm:ss"
	std::string to_string(const time& t);

	// Преобразовать в строку в формате "yyyy.MM.dd"
	std::string to_string(const date& d);

	// Преобразовать в строку в формате "yyyy.MM.dd HH:mm:ss"
	std::string to_string(const datetime& dt);

}
