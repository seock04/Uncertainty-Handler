#include<iostream>
#include<set>
#include<unordered_map>
//#include<vector>
using namespace std;

#define MAX_BIKE 20001
#define MAX_USER 10001
#define MAXN		100
#define MAXL		8

enum STATE { RENTED, RENEW, WAITING };

int durable_time;


struct Bike {
	STATE state;
	int runtime;
	int startTime; //사용자가 타기 시작한 시간 or 새 자전거 운송을 시작 한 시간
};
Bike bikes[MAX_BIKE];
int bike_count;

int createBike()
{
	bikes[bike_count].state = WAITING;
	bikes[bike_count].runtime = 0;
	bikes[bike_count].startTime = -1;

	return bike_count++;
}

struct cmp_runtime {
	bool operator()(const int a, const int b) const {
		return (bikes[a].runtime < bikes[b].runtime) || (bikes[a].runtime == bikes[b].runtime && a < b);
	}
};

struct cmp_starttime {
	bool operator()(const int a, const int b) const {
		return (bikes[a].startTime < bikes[b].startTime) || (bikes[a].startTime == bikes[b].startTime && a < b);
	}
};

struct Station {
	int deliveryTime;
	set<int, cmp_runtime>bikeList;
	set<int, cmp_starttime>bikeInDeliveryList;

	void init(int _deliveryTime)
	{
		deliveryTime = _deliveryTime;
		bikeList.clear();
		bikeInDeliveryList.clear();
	}
};
Station stations[MAXN];
int station_count;

int createStation(int _deliveryTime)
{
	stations[station_count].init(_deliveryTime);
	return station_count++;
}

unordered_map<string, int> user_map;

struct User {
	int ticketPaidTime;
	int ticketValidTime;
	int bikeId;

	void init() {
		ticketPaidTime = -1;
		ticketValidTime = -1;
		bikeId = -1;
	}

	bool isTicketValid(int _curTime) {
		if (ticketPaidTime == -1 || ticketValidTime == -1) return false;

		return _curTime < ticketPaidTime + ticketValidTime;
	}
};
User users[MAX_USER];
int user_count;

int createUser()
{
	users[user_count].init();
	return user_count++;
}

int fn_count;
void init(int N, int durableTime, int deliveryTimes[MAXN])
{
	fn_count = 1;
	bike_count = 0;
	station_count = 0;
	user_count = 0;
	durable_time = durableTime;

	for (register int i = 0; i < N; i++) {
		createStation(deliveryTimes[i]);
	}

	user_map.clear();

	//cout << fn_count++ << " init " << N << " " << durableTime << "\n";
}

void addBicycle(int cTimestamp, int pID, int bicycleNum)
{
	/*
	stations[pID] 의 bikeList 에 bike를 bicycleNum 만큼 생성해서 추가
	*/
	//cout << fn_count++ << " addBicycle " << cTimestamp << " " << pID << " " << bicycleNum << "\n";
	for (register int i = 0; i < bicycleNum; i++) {
		stations[pID].bikeList.insert(createBike());
	}
	//cout << "# " << stations[pID].bikeList.size() << "\n";
}

void buyTicket(int cTimestamp, char uName[MAXL], int validTime)
{
	/*
		uName 사용자가 기존에 존재 하는 사용자 인지 아닌지 확인 해서, 그 사용자의 tiket 내용을 업데이트 한다.
	*/
	//cout << fn_count++ << " buyTicket " << cTimestamp << " " << uName << " " << validTime << "\n";
	int uid = -1;
	if (user_map.find(uName) == user_map.end()) {
		uid = createUser();
		user_map[uName] = uid;
	}
	else {
		uid = user_map[uName];
	}

	// check validTime
	if (users[uid].isTicketValid(cTimestamp)) {
		// 유효기간을 validTime 만큼 연장한다.
		users[uid].ticketValidTime += validTime;
	} 
	else {
		//users[uid].ticketPaidTime, ticketValidTime 을 cTimestamp 과 validTime 으로 업데이트 한다.
		users[uid].ticketPaidTime = cTimestamp;
		users[uid].ticketValidTime = validTime;
	}

}

bool isWaitingSate(int index)
{
	return bikes[index].state == WAITING;
}

int rentBicycle(int cTimestamp, char uName[MAXL], int pID)
{
	/*
		uName 가 tiket 이 있는지 확인하고 stations[pID] 에서 대여 가능한 자전거를 확인 한 후 대여해 준다.

		1) stations[pID].bikeInDeliveryList 에 있는 bike 중 delivery 완료 된 것들은 bikeList 로 옮겨줌
		2) uName의 대여 가능여부 체크
			- 이미 빌린 자전거가 있으면 return
			- 대여소에 남은 자전거가 없으면 return
			- uName 의 users[uid].isValidTime() 가 true가 아니면 return

		3) stations[pID].bikeList 의 top 을 가져와서 users[uid].bikeId 에 넣어줌
		   - bikes[bid]의 state 변경
		4) 대여 성공시 return bikes[bid].runtime, or return -1
	*/
	//cout << fn_count++ << " rentBicycle " << cTimestamp << " " << uName << " " << pID << "\n";
	int uid = -1;
	if (user_map.find(uName) == user_map.end()) {
		uid = createUser();
		user_map[uName] = uid;
	}
	else {
		uid = user_map[uName];
	}

	if (users[uid].bikeId != -1) {
		//cout << "# aleady rented " << "\n";
		return -1;
	}

	if (!users[uid].isTicketValid(cTimestamp)) {
		//cout << "# ticket is not valid " << "\n";
		return -1;
	}

	int t_delivery_bike_count = stations[pID].bikeInDeliveryList.size();
	int t_available_bike_count = stations[pID].bikeList.size();
	if (!(t_delivery_bike_count + t_available_bike_count)) {
		//cout << "# no bike available " << "\n";
		return -1;
	}

	// move waiting bike if it's delivered
	int index = 0;
	while (!stations[pID].bikeInDeliveryList.empty()) {
		int t_bid = *(stations[pID].bikeInDeliveryList.begin());

		int waitingTime = cTimestamp - bikes[t_bid].startTime;
		if (waitingTime >= stations[pID].deliveryTime) {

			bikes[t_bid].state = WAITING;
			bikes[t_bid].startTime = -1;
			bikes[t_bid].runtime = 0;

			stations[pID].bikeInDeliveryList.erase(stations[pID].bikeInDeliveryList.begin());
			stations[pID].bikeList.insert(t_bid);
		}
		else {
			break;
		}
	}


	//rent bike
	int ret = -1;
	if (stations[pID].bikeList.size() > 0) {
		int t_bid = *(stations[pID].bikeList.begin());
		stations[pID].bikeList.erase(stations[pID].bikeList.begin());

		bikes[t_bid].state = RENTED;
		bikes[t_bid].startTime = cTimestamp;

		users[uid].bikeId = t_bid;
		ret = bikes[t_bid].runtime;
	}
	//cout << "# ret:" << ret << "\n";
	return ret;
}

int returnBicycle(int cTimestamp, char uName[MAXL], int pID)
{
	/*
		uName 가 가지고 있는 자전거가 있는지 확인 하고 있으면 pID station에 해당 자전거를 반납 한다.

		uName 의 자전거 반납
		1) 빌린 자전거가 없으면 return -1
		2) 빌린 자전거가 있고 유효기간이 지나지 않았으면 return 0
		3) 빌린 자전거가 있고 유효기간이 지났으면 return 연체된 시간

		stations[pID] 의 반납된 자전거 처리 절차
		0) bike의 state 변경
		1) 반납된 자전가의 runtime이 durable_time을 초과 했을 때
			stations[pID].bikeInDeliveryList 에 추가
		2) 그렇지 않은 경우
			stations[pID].bikeList 에 추가
	*/
	//cout << fn_count++ << " returnBicycle " << cTimestamp << " " << uName << " " << pID << "\n";

	int uid = -1;
	if (user_map.find(uName) == user_map.end()) {
		uid = createUser();
		user_map[uName] = uid;
	}
	else {
		uid = user_map[uName];
	}

	int ret = -1;
	if (users[uid].bikeId == -1) {
		//cout << "#  no rented bike " << "\n";
		return ret;
	}
	if (users[uid].isTicketValid(cTimestamp)) {
		//cout << "# ticket is valid " << "\n";
		ret = 0;
	}
	else { // delayed
		ret = cTimestamp - (users[uid].ticketPaidTime + users[uid].ticketValidTime - 1);
		//cout << "# delayed " << "\n";
	}
	int r_bid = users[uid].bikeId;
	users[uid].bikeId = -1;


	bikes[r_bid].runtime += cTimestamp - bikes[r_bid].startTime;
	bikes[r_bid].startTime = cTimestamp;

	if (bikes[r_bid].runtime > durable_time) {
		bikes[r_bid].state = RENEW;
		stations[pID].bikeInDeliveryList.insert(r_bid);
	}
	else {
		bikes[r_bid].state = WAITING;
		stations[pID].bikeList.insert(r_bid);
	}

	//cout << "# ret:" << ret << "\n";
	return ret;
}
