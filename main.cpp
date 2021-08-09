#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
struct date
{

    int day;
    int month;
    int year;
};
struct booking
{
    int desk ;
    float weight ;
};
///transport
int transport_id;
string manufacturer;
date made_date;
int speed;
int property_type;
int transport_type;

///wilderness
int engine_num;
float vehicle_length;

///car
int door_num;
float car_total_weight;
float car_bags_weight;
///buses
int seat_num;
float bus_total_weight;
float bus_bags_weight;
///trucks
float tare_weight;
float max_weight;
float good_height;
float good_weight;

///aerial
int air_engine_num;
float plane_length ;

///passenger air
int air_seat_num ;
float air_max_bag_weight;
float air_bags_weight;
///shipment air
float air_tare_weight;
float air_max_weight;
float air_good_weight;




///journey
int journey_id ;
date journey_date ;
string from ;
string to ;
float gross_weight ;
int number;
booking *booking_record;
float goods_weight ;
float max_goods_weight;
string transport_name;

void aerial_scan ()
{
    cout <<"Enter the number of motors for plane: " ;
    cin >> air_engine_num ;
    cout <<"Enter the plane length: " ;
    cin >> plane_length ;
}
void wild_scan()
{
    cout <<"Enter the number of engine: ";
    cin >> engine_num ;
    cout<<"Enter the length of vehicle: " ;
    cin >> vehicle_length ;
}
void trans_scan()
{
    cout<<"Enter the transport id: " ;
    cin >> transport_id ;
    cout << "Enter the name of the manufacturer: ";
    cin >> manufacturer ;
    cout<<"Enter the industry Date of the transport:"<<endl;
    ret:
    cout<<"Year: " ;
    cin >> made_date.year ;
    if(made_date.year >2017||made_date.year<1970)
    {
        cout<<"This date is false!!"<<endl;
        goto ret;
    }
    ret1:
    cout <<"Month: ";
    cin >> made_date.month ;
    if(made_date.month >12||made_date.month<1)
    {
        cout<<"This date is false!!"<<endl;
        goto ret1;
    }
    cout << "Enter the transport speed: " ;
    cin >> speed ;
    cout <<"Enter the number of property type:"<<endl;
    cout<<"1)General. \t\t2)Particular. \t\t3)Internationality form."<<endl;
    k:
    cout<<"Property type is: ";
    cin >> property_type ;
    if(property_type>3||property_type<1)
    {
         cout<<"Sorry you are enter the default number!!"<<endl;
         goto k;
    }
}
void journey_scan()
{
    cout <<"Enter the id of the journey: " ;
    cin>> journey_id ;
    cout<<"Enter the date of the journey: "<<endl;
    j1:
    cout<<"Year: " ;
    cin >> journey_date.year ;
    if(journey_date.year >2017||journey_date.year <1970)
    {
        cout<<"This date is false!!"<<endl;
        goto j1;
    }
    j2:
    cout <<"Month: ";
    cin >> journey_date.month ;
    if(journey_date.month >12||journey_date.month<1)
    {
        cout<<"This date is false!!"<<endl;
        goto j2;
    }
    j3:
    cout<<"Day: ";
    cin>>journey_date.day;
    if(journey_date.day>31||journey_date.day<1)
     {
          cout<<"This date is false!!"<<endl;
          goto j3;
     }
    if(journey_date.day==31)
     {
         if(journey_date.month==2||journey_date.month==4||journey_date.month==6||journey_date.month==9||journey_date.month==11)
            cout<<"This date is false!!"<<endl;
            goto j3;
     }
    cout<<"Enter the gross weight in journey: ";
    cin >> gross_weight ;
    cout<<"Enter the good weight in journey: ";
    cin >> goods_weight ;
    cout<<"Enter the start city: ";
    cin >> from ;
    cout<<"Enter the end city: ";
    cin >> to ;
    cout<<"Enter the number of seats: ";
    cin >> number ;
    booking_record = new booking [number];
    cout<<"\nEnter the state of all seats and weight bags for all person.\nNote: If seat is busy enter 1 else enter 0"<<endl;
    for(int i=0 ; i<number ; i++ )
    {
        cout<<"The "<<i+1<<" seat is: ";
        cin>>booking_record[i].desk;
        if(booking_record[i].desk==0){
            continue;
        }
        re:
        cout<<"The "<<i+1<<" bags weight of person in the seat: ";
        cin>>booking_record[i].weight;
        if(booking_record[i].weight>25)
        {
            cout<<"\nThis weight is too high!!\nPlease less some of your bags.\n"<<endl;
            goto re;
        }
    }
    cout<<endl;
}
class transport
{
protected:
    int transport_id;
    string manufacturer;
    date made_date;
    int speed;
    int property_type;
    int transport_type;
public:
    transport()
    {
        transport_id = 0;
        manufacturer = "";
        made_date.month = 0;
        made_date.year = 0;
        speed = 0;
        property_type = 0;
        transport_type = 0;
    }
    transport(int transport_id , string manufacturer,date made_date,int speed,int property_type,int transport_type)
    {
        this -> transport_id = transport_id;
        this -> made_date = made_date;
        this -> manufacturer = manufacturer;
        this -> speed = speed;
        this -> property_type = property_type;
        this -> transport_type = transport_type;

    }
    transport(transport &temp)
    {
        this -> transport_id = temp.transport_id;
        this -> made_date = temp.made_date;
        this -> manufacturer = temp.manufacturer;
        this -> speed = temp.speed;
        this -> property_type = temp.property_type;
        this -> transport_type = temp.transport_type;
    }
    virtual string get_name() = 0;
    virtual int get_trans_id()=0;
    virtual void warning_of_gross() =0;
    virtual void warning_of_bags()=0;
    virtual void print() =0;
    ~transport();
};
class wilderness: public transport
{
private:
    int engine_num;
    float vehicle_length;
public:
    wilderness():transport()
    {
        engine_num = 0;
        vehicle_length = 0;
    }
    wilderness(int engine_num,float vehicle_length, int transport_id , string manufacturer,date made_date,int speed,int property_type,int transport_type)
    :transport( transport_id , manufacturer, made_date, speed,property_type,transport_type)
    {
       this -> engine_num = engine_num;
       this -> vehicle_length = vehicle_length;
    }
    wilderness(wilderness &temp):transport(temp)
    {
        this -> engine_num = temp.engine_num;
        this -> vehicle_length = temp.vehicle_length;
    }
    void print()
    {
        cout<<"The engine number is: "<<engine_num<<endl;
        cout<<"The vehicle length is: "<<vehicle_length<<endl;
    }
    ~wilderness();
};
class buses :public wilderness
{
private:
    int seat_num;
    float bus_total_weight;
    float bus_bags_weight;
public:
    buses():wilderness()
    {
        seat_num = 0;
        bus_total_weight = 0;
        bus_bags_weight = 0;
    }
    buses(int seat_num,float bus_total_weight,float bus_bags_weight,int engine_num,float vehicle_length, int transport_id , string manufacturer,date made_date,int speed,int property_type,int transport_type)
    :wilderness( engine_num, vehicle_length,transport_id , manufacturer,made_date, speed, property_type, transport_type )
    {
        this -> seat_num = seat_num;
        this -> bus_total_weight = bus_total_weight;
        this -> bus_bags_weight = bus_bags_weight;
    }
    buses(buses &temp):wilderness(temp)
    {
        this -> seat_num = temp.seat_num ;
        this -> bus_total_weight = temp.bus_total_weight;
        this -> bus_bags_weight = temp.bus_bags_weight;
    }
    string get_name()
    {
        return "Buses" ;
    }
    int get_trans_id()
    {
        return transport_id;
    }
    void print()
    {
        cout<<"The seats number is: "<<seat_num<<endl;
        cout<<"The total weight is: "<<bus_total_weight<<endl;
        cout<<"The bags weight is: "<<bus_bags_weight<<endl;
    }
    void warning_of_bags()
    {
        if(bus_bags_weight>bus_total_weight)
            cout<<"ERROR!!.. the bags weight is very high."<<endl;
    }
    void warning_of_gross(){}
    ~buses();
};
class cars :public wilderness
{
private:
    int door_num;
    float car_total_weight;
    float car_bags_weight;
public:
    cars():wilderness()
    {
        door_num = 0;
        car_bags_weight = 0;
        car_total_weight = 0;
    }
    cars(int door_num, float car_total_weight,float car_bags_weight,int engine_num,float vehicle_length, int transport_id , string manufacturer,date made_date,int speed,int property_type,int transport_type )
    :wilderness( engine_num, vehicle_length,transport_id , manufacturer,made_date, speed, property_type, transport_type )
    {
        this -> door_num = door_num;
        this -> car_total_weight = car_total_weight;
        this -> car_bags_weight = car_bags_weight;
    }
    cars (cars &temp):wilderness(temp)
    {
        this -> door_num = temp.door_num;
        this -> car_total_weight = temp.car_total_weight;
        this -> car_bags_weight = temp.car_bags_weight;
    }
    string get_name ()
    {
        return "Car" ;
    }
    int get_trans_id ()
    {
        return transport_id;
    }
    void print()
    {
        cout<<"The door's number is: "<<door_num<<endl;
        cout<<"The total weight is: "<<car_total_weight<<endl;
        cout<<"The bags weight is: "<<car_bags_weight<<endl;
    }
    void warning_of_bags()
    {
        if(car_bags_weight>car_total_weight)
            cout<<"ERROR!!.. the bags weight is very high."<<endl;
    }
    void warning_of_gross(){}
    ~cars();
};
class trucks :public wilderness
{
private:
    float tare_weight;
    float max_weight;
    float good_height;
    float good_weight;
public:
    trucks():wilderness()
    {
        tare_weight = 0;
        max_weight = 0;
        good_height = 0;
        good_weight = 0;
    }
    trucks (float tare_weight ,float  max_weight ,float good_height,float good_weight,int engine_num,float  vehicle_length, int transport_id, string manufacturer,date made_date,int speed,int property_type,int transport_type )
    :wilderness( engine_num, vehicle_length,transport_id , manufacturer,made_date, speed, property_type, transport_type )
    {
        this -> tare_weight = tare_weight;
        this -> max_weight = max_weight;
        this -> good_height = good_height;
        this -> good_weight = good_weight;
    }
    trucks(trucks &temp):wilderness(temp)
    {
        this -> tare_weight = temp.tare_weight;
        this -> max_weight = temp.max_weight;
        this -> good_height = temp.good_height;
        this -> good_weight = temp.good_weight;
    }
    string get_name ()
    {
        return "Trucks";
    }
    int get_trans_id ()
    {
        return transport_id;
    }
    void print ()
    {
        cout<<"The tare weight is: "<<tare_weight<<endl;
        cout<<"The max weight is: "<<max_weight<<endl;
        cout<<"The good height is: "<<good_height<<endl;
        cout<<"The good weigh is: "<<good_weight<<endl;
    }
    void warning_of_bags(){}
    void warning_of_gross()
    {
     if((good_weight+tare_weight)>max_weight)
        {
            cout<<"ERROR!!.. the goods weight is very high."<<endl;
        }
    }
    ~trucks();
};
class aerial :public transport
{
private :
    int air_engine_num ;
    float plane_length ;
public :
    aerial():transport ()
    {
        air_engine_num = 0 ;
        plane_length = 0 ;
    }
    aerial(int air_engine_num ,float plane_length , int transport_id , string manufacturer,date made_date,int speed,int property_type,int transport_type)
    :transport( transport_id ,  manufacturer, made_date, speed,property_type,transport_type)
    {
        this -> air_engine_num = air_engine_num;
        this -> plane_length = plane_length ;

    }
    aerial(aerial &temp):transport(temp)
    {
        this -> air_engine_num = temp.air_engine_num ;
        this -> plane_length = temp.plane_length ;
    }
    void print()
    {
        cout<<"The air engine number is: "<<air_engine_num<<endl;
        cout<<"The plane length is: "<<plane_length<<endl;
    }
    ~aerial();
};
class passenger_air :public aerial
{
private :
    int air_seat_num ;
    float air_max_bag_weight ;
    float air_bags_weight;
public :
    passenger_air () : aerial()
    {
        air_seat_num = 0 ;
        air_max_bag_weight = 0 ;
        air_bags_weight = 0;
    }
    passenger_air (int air_seat_num ,float air_bags_weight,float air_max_bag_weight , int air_engine_num , float plane_length , int transport_id , string manufacturer,date made_date,int speed,int property_type,int transport_type)
    :aerial( air_engine_num , plane_length , transport_id, manufacturer,made_date,speed, property_type, transport_type)
    {
        this -> air_seat_num = air_seat_num ;
        this -> air_max_bag_weight = air_max_bag_weight ;
        this -> air_bags_weight = air_bags_weight ;
    }
    passenger_air(passenger_air &temp):aerial(temp)
    {
        this -> air_seat_num = temp.air_seat_num ;
        this -> air_max_bag_weight = temp.air_max_bag_weight ;
        this -> air_bags_weight = temp.air_bags_weight ;
    }
    string get_name ()
    {
        return "Passenger Airliners" ;
    }
    int get_trans_id ()
    {
        return transport_id;
    }
    void print ()
    {
        cout<<"The air seat number is: "<<air_seat_num<<endl;
        cout<<"The air max bag weight is: "<<air_max_bag_weight<<endl;
        cout<<"The air bags weight is: "<<air_bags_weight<<endl;
    }
    void warning_of_bags()
    {
        if(air_bags_weight>air_max_bag_weight)
            cout<<"ERROR!!.. the bags weight is very high."<<endl;
    }
    void warning_of_gross(){}
    ~passenger_air();
};
class shipment_air :public aerial
{
private :
    float air_tare_weight ;
    float air_max_weight ;
    float air_good_weight;
public :
    shipment_air () : aerial()
    {
        air_tare_weight = 0 ;
        air_max_weight = 0 ;
        air_good_weight = 0;
    }
    shipment_air (int air_tare_weight , float air_max_weight,float air_good_weight , int air_engine_num , float plane_length , int transport_id, string manufacturer,date made_date,int speed,int property_type,int transport_type)
    :aerial( air_engine_num , plane_length , transport_id, manufacturer,made_date,speed, property_type, transport_type)
    {
        this -> air_tare_weight = air_tare_weight ;
        this -> air_max_weight = air_max_weight ;
        this -> air_good_weight = air_good_weight;
    }
    shipment_air(shipment_air &temp):aerial(temp)
    {
        this -> air_tare_weight = temp.air_tare_weight ;
        this -> air_max_weight = temp.air_max_weight ;
        this -> air_good_weight = temp.air_good_weight;
    }
    string get_name ()
    {
        return "Cargo planes" ;
    }
    int get_trans_id ()
    {
        return transport_id;
    }
    void print ()
    {
        cout<<"The air tare weigh is: "<<air_tare_weight<<endl;
        cout<<"The air max weigh is: "<<air_max_weight<<endl;
        cout<<"The air good weigh is: "<<air_good_weight<<endl;
    }
    void warning_of_bags(){}
    void warning_of_gross()
    {
        if((air_good_weight+air_tare_weight)>air_max_weight)
        {
            cout<<"ERROR!!.. the goods weight is very high."<<endl;
        }
    }
    ~shipment_air();
};

class journey
{
private :
    int journey_id ;
    transport *journey_trans ;
    date journey_date ;
    string from ;
    string to ;
    int number ;
    booking *booking_record;
    float gross_weight ;
    float goods_weight ;
public :
    journey ()
    {
        journey_id = 0;
        journey_date.day = 0 ;
        journey_date.month = 0 ;
        journey_date.year = 0 ;
        booking_record->desk = 0;
        booking_record->weight = 0;
        from = "" ;
        to = "";
        number = 0;
        gross_weight = 0;
        goods_weight = 0;
    }
    journey ( int journey_id ,transport *journey_trans , date journey_date , string from , string to , int number , booking *booking_record, float gross_weight ,float goods_weight )
    {
        this -> journey_id = journey_id;
        this -> journey_trans = journey_trans;
        this -> journey_date = journey_date ;
        this -> from = from ;
        this -> to = to ;
        this -> number = number;
        this -> booking_record = booking_record ;
        this -> gross_weight = gross_weight ;
        this -> goods_weight = goods_weight ;
    }
    journey ( journey &temp )
    {
        this -> journey_id = temp.journey_id;
        this -> journey_trans = temp.journey_trans;
        this -> journey_date = temp.journey_date ;
        this -> from = temp.from ;
        this -> to = temp.to ;
        this -> number = temp.number;
        this -> booking_record = temp.booking_record ;
        this -> gross_weight = temp.gross_weight ;
        this -> goods_weight = temp.goods_weight ;
    }
    transport* get_transport()
    {
        return journey_trans ;
    }
    int get_journey_id()
    {
        return journey_id;
    }
    string get_from ()
    {
        return from ;
    }
    string get_to ()
    {
        return to ;
    }
    date get_journey_date ()
    {
        return journey_date ;
    }
    int get_number()
    {
        return number;
    }
    booking *get_booking_record()
    {
        return booking_record;
    }
    void print ()
    {
        cout <<"The journey id is: "<<journey_id<<endl;
        cout<<"The date of the journey is: "<<journey_date.day<<"/"<<journey_date.month<<"/"<<journey_date.year<<endl;
        cout<<"The gross weight in journey is: "<<gross_weight<<endl;
        cout<<"The goods weight in journey is: "<<goods_weight<<endl;
        cout<<"The start city is: "<<from<<"\tThe end city is: "<<to<<endl;
        cout<<"the number of seat is: "<<number<<endl;
    }
    void warning_of_journey()
    {
        if(goods_weight>gross_weight)
            cout<<"ERROR!!.. the goods weight is very high."<<endl;
    }
    ~journey();
};
struct transport_node
{
    transport *trans;
    transport_node *next;
};
void scan(transport_node **trans_head,transport *p)
{
    transport_node *temp = new transport_node;
    temp -> trans = p;
    temp -> next = *trans_head;
    *trans_head = temp;
}
void print(transport_node *head )
{
    while (head != NULL)
    {
         cout<<head -> trans;
         head = head -> next;
    }
}
transport *transport_id_search (transport_node *head , int trans_id)
{
    while (head != NULL)
    {
        if ((head -> trans) -> get_trans_id() == trans_id)
        {
            cout <<"The name of transport is: "<<(head -> trans) -> get_name()<<endl;
            return head->trans;
        }
        head = head -> next ;
    }
    cout <<"Sorry, The number you entered does not exist."<<endl;
    return NULL ;
}
struct journey_node
{
    journey *jour ;
    journey_node *next ;
};
void scan(journey_node **journey_head,journey *p)
{
    journey_node *temp = new journey_node;
    temp -> jour = p;
    temp -> next = *journey_head;
    *journey_head = temp;
}
void print(journey_node *head )
{
    while (head != NULL)
    {
         cout<<head ->jour;
         head = head -> next;
    }
}
void print_journey_id(string transport_name, string from , string to , journey_node *jour_haed )
{
    int i=0 ;
    while (jour_haed !=NULL )
    {
        transport *temp = (jour_haed->jour)->get_transport();
        if ((temp->get_name()==transport_name)&& ((jour_haed->jour)->get_from()== from) && ((jour_haed->jour)->get_to()==to))
        {
            i++;
            cout<<"The "<<i<<" journey id is: "<< (jour_haed->jour)->get_journey_id()<<endl ;
            return ;
        }
        jour_haed = jour_haed->next ;
    }
    cout <<"Not found!"<<endl;
}
bool help(date a , date b , date c)
{
    long long a1 =a.day*24+a.month*30+a.year*365 ;
    long long b1 =b.day*24+b.month*30+b.year*365 ;
    long long c1 =c.day*24+c.month*30+c.year*365 ;
    return (c1>a1&&b1>c1) || (c1<a1&&b1<c1) ;
}
int calc_number_of_passenger(date start,date End , string transport_name, journey_node *jour_haed )
{
    int i=0 ;
    while(jour_haed!=NULL)
    {
        if ((jour_haed->jour)->get_transport()->get_name()== transport_name&& help(start , End , (jour_haed ->jour)->get_journey_date() ))
        {
            number=(jour_haed->jour)->get_number();
            booking_record=(jour_haed->jour)->get_booking_record();
            for(int k=0 ; k<number ; k++ )
            {
                if(booking_record[i].desk==1)
                    i++;
            }
        }
        jour_haed = jour_haed -> next ;
    }
    return i ;
}
void print_info(string transport_name,journey_node *jour_haed )
{
    while (jour_haed != NULL )
    {
        transport *temp = (jour_haed -> jour) -> get_transport();
        if (temp->get_name() == transport_name )
        {
            (jour_haed->jour) -> print();
            cout <<"\n\n-------------------------\n\n" ;
        }
        jour_haed = jour_haed -> next ;
    }
}
int main()
{
    int z ,y ,o ,t ,r ;
    transport *p;
    transport_node *trans_head=NULL ;
    journey_node *journey_head=NULL ;
    transport *journey_trans ;
    journey *j ;
    her:
    system("cls");
    cout <<"Please select your choice:\n1)Enter the data for vehicle."<<endl;
    cout<<"2)Search for transport.\n3)Enter data for journey."<<endl;
    cout<<"4)Printing the numbers of journeys for vehicle special between two city."<<endl;
    cout<<"5)Count the number of passengers who traveled on board a particular vehicle during a specific period."<<endl;
    cout<<"6)printing all data for particular vehicle."<<endl;
    cout<<"7)End program."<<endl;
    cout<<"Your choice is: ";
    cin>>y;
    system("cls");
switch(y)
{
    case 1:
        {
            here:
            system("cls");
            cout <<"Enter the number for vehicle you want:\n1)Car.\t\t2)Passenger Airliners."<<endl;
            cout<<"3)Trucks.\t4)Cargo planes.\n5)Buses.\t6)End vehicle data"<<endl;
            cout<<"Your choice is: ";
            cin >> z ;
            system("cls");
    switch(z)
    {
        case 1:
            {
                ///car
                cout<<"You are select the Car."<<endl;
                trans_scan();
                transport_type=1;
                wild_scan();
                cout <<"Enter the number of car's doors: " ;
                cin >> door_num ;
                cout <<"Enter the car total weight: " ;
                cin >> car_total_weight;
                cout <<"Enter the car bags weight: " ;
                cin >> car_bags_weight ;
                p = new cars( door_num,car_total_weight,car_bags_weight, engine_num,vehicle_length,  transport_id ,manufacturer,made_date,speed,property_type,transport_type );
                scan(&trans_head , p) ;
                p -> warning_of_bags();
                cout<<"\nDo you want add new data vehicle?\nif your answer is YES enter 1 else enter any number."<<endl;
                cout<<"your choice is: ";
                cin>>o;
                cout<<endl;
                if(o==1)
                {
                    goto here ;
                    break;
                }
                else
                    goto her;
            }
        case 2:
            {
                ///passenger Airliners
                cout<<"You are select the Passenger Airliners."<<endl;
                trans_scan();
                transport_type=2;
                aerial_scan();
                cout <<"Enter the number of seat: ";
                cin >> air_seat_num ;
                cout << "Enter the max bag weight: ";
                cin >> air_max_bag_weight ;
                cout<<"Enter the air bags weight: ";
                cin>> air_bags_weight;
                p=new passenger_air (air_seat_num ,air_bags_weight,air_max_bag_weight , air_engine_num , plane_length , transport_id , manufacturer, made_date, speed, property_type, transport_type);
                scan( &trans_head , p );
                p -> warning_of_bags();
                cout<<"\nDo you want add new data vehicle?\nIf your answer is YES enter 1 else enter any number."<<endl;
                cout<<"Your choice is: ";
                cin>>o;
                cout<<endl;
                if(o==1)
                {
                    goto here ;
                    break;
                }
                else
                    goto her;
            }

        case 3:
            {
                ///Trucks
                cout<<"You are select the Trucks."<<endl;
                trans_scan();
                transport_type=4;
                wild_scan();
                cout << "Enter the tare weight: " ;
                cin >> tare_weight;
                cout << "Enter the max weight: " ;
                cin >> max_weight;
                cout << "Enter the good height: " ;
                cin >> good_height;
                cout << "Enter the good weigh: " ;
                cin >> good_weight;
                p=new trucks (tare_weight ,max_weight , good_height,good_weight,engine_num, vehicle_length, transport_id , manufacturer,made_date, speed, property_type,transport_type );
                scan(&trans_head , p) ;
                p->warning_of_gross();
                cout<<"\nDo you want add new data vehicle?\nIf your answer is YES enter 1 else enter any number."<<endl;
                cout<<"Your choice is: ";
                cin>>o;
                cout<<endl;
                if(o==1)
                {
                    goto here ;
                    break;
                }
                else
                    goto her;
            }
        case 4:
            {
                ///Cargo planes
                cout<<"You are select the Cargo planes."<<endl;
                trans_scan();
                transport_type=5;
                aerial_scan();
                cout << "Enter the tare weight: " ;
                cin >> air_tare_weight;
                cout << "Enter the max weight: " ;
                cin >> air_max_weight;
                cout<<"Enter the air good weigh: ";
                cin>>air_good_weight;
                p=new shipment_air (air_tare_weight ,air_max_weight ,air_good_weight, air_engine_num , plane_length , transport_id, manufacturer, made_date, speed, property_type, transport_type);
                scan(&trans_head , p) ;
                p->warning_of_gross();
                cout<<"\nDo you want add new data vehicle?\nIf your answer is YES enter 1 else enter any number."<<endl;
                cout<<"Your choice is: ";
                cin>>o;
                cout<<endl;
                if(o==1)
                {
                    goto here ;
                    break;
                }
                else
                    goto her;
            }

        case 5:
            {
                ///buses
                cout<<"You are select the Buses."<<endl;
                trans_scan();
                transport_type=7;
                wild_scan();
                cout << "\nEnter the number of seats: " ;
                cin >> seat_num ;
                cout << "\nEnter the bus total weight: " ;
                cin >> bus_total_weight ;
                cout << "\nEnter the bus bags weight: " ;
                cin >> bus_bags_weight;
                p = new buses(seat_num,bus_total_weight,bus_bags_weight , engine_num,vehicle_length,  transport_id ,manufacturer,made_date,speed,property_type,transport_type  );
                scan(&trans_head , p) ;
                p -> warning_of_bags();
                cout<<"\nDo you want add new data vehicle?\nIf your answer is YES enter 1 else enter any number."<<endl;
                cout<<"Your choice is: ";
                cin>>o;
                cout<<endl;
                if(o==1)
                    goto here ;
                else
                    goto her;
            }
        case 6:
            {
                goto her;
            }
        default:
          {
            cout<<"Sorry you are enter the default number!!\n"<<endl;
            cout<<endl;
            system("pause");
            system("cls");
            goto here;
          }
    }
        }
    case 2:
        {
            cout<<"Enter the transport id you want to search: ";
            cin>>transport_id ;
            transport_id_search(trans_head,transport_id);
            cout<<endl;
            system("pause");
            system("cls");
            goto her;
        }
    case 3:
        {
            do
            {
                cout <<"Enter the transport id: " ;
                cin >> transport_id ;

                journey_trans=transport_id_search(trans_head,transport_id);
            }while (journey_trans == NULL);
            journey_scan();
            j= new journey(journey_id ,journey_trans , journey_date , from , to , number , booking_record, gross_weight ,goods_weight);
            scan(&journey_head , j );
            j -> warning_of_journey();
            cout<<endl;
            system("pause");
            system("cls");
            goto her;
        }
    case 4:
        {
            cout <<"Enter the number for vehicle you want to show her journey Record:\n1)Car.\t\t2)Passenger Airliners."<<endl;
            cout<<"3)Trucks.\t4)Cargo planes.\t\t\t5)Buses."<<endl;
            cout<<"Your choice is: ";
            f:
            cin>>t;
            if(t==1)
            transport_name ="Car" ;
            else if(t==2)
            transport_name ="Passenger Airliners" ;
            else if(t==3)
            transport_name ="Trucks" ;
            else if(t==4)
            transport_name ="Cargo planes" ;
            else if(t==5)
            transport_name ="Buses" ;
            else
            {
                cout<<"You are enter the default number!!"<<endl;
                goto f;
            }
            cout<<"Enter the city of start: ";
            cin>>from;
            cout<<"Enter the city of finality: ";
            cin>>to;
            print_journey_id(transport_name,from , to ,journey_head);
            cout<<endl;
            system("pause");
            system("cls");
            goto her;
        }
    case 5:
        {
            date journey_start_date;
            date journey_end_date;
            cout <<"Enter the number for vehicle you want to show her journey Record:\n1)Car.\t\t2)Passenger Airliners.\t\t3)Trucks"<<endl;
            cout<<"4)Cargo planes.\t5)Buses. ."<<endl;
            cout<<"Your choice is: ";
            u:
            cin>>t;
            if(t==1)
            transport_name ="Car" ;
            else if(t==2)
            transport_name ="Passenger Airliners" ;
            else if(t==3)
            transport_name ="Trucks" ;
            else if(t==4)
            transport_name ="Cargo planes" ;
            else if(t==5)
            transport_name ="Buses" ;
            else
            {
                cout<<"You are enter the default number!!"<<endl;
                goto u;
            }
            cout<<"Enter the date of start:"<<endl;
            t1:
            cout<<"Year : ";
            cin>>journey_start_date.year;
            if(journey_start_date.year  >2016||journey_start_date.year <1970)
            {
                cout<<"This date is false!!"<<endl;
                goto t1;
            }
            t2:
            cout <<"Month : ";
            cin >> journey_start_date.month ;
            if(journey_start_date.month >12||journey_start_date.month<1)
            {
                cout<<"This date is false!!"<<endl;
                goto t2;
            }
            t3:
            cout<<"Day : ";
            cin>>journey_start_date.day;
            if(journey_start_date.day>31||journey_start_date.day<1)
               {
                   cout<<"This date is false!!"<<endl;
                   goto t3;
               }
            if(journey_start_date.day==31)
             {
                 if(journey_start_date.month==2||journey_start_date.month==4||journey_start_date.month==6||journey_start_date.month==9||journey_start_date.month==11)
                    cout<<"This date is false!!"<<endl;
                    goto t3;
             }
            cout<<"Enter the date of end:"<<endl;
            k1:
            cout<<"Year : ";
            cin>>journey_end_date.year;
            if(journey_end_date.year  >2016||journey_end_date.year <1970)
            {
                cout<<"This date is false!!"<<endl;
                goto k1;
            }
            k2:
            cout <<"Month : ";
            cin >> journey_end_date.month ;
            if(journey_end_date.month >12||journey_end_date.month<1)
            {
                cout<<"This date is false!!"<<endl;
                goto k2;
            }
            k3:
            cout<<"Day : ";
            cin>>journey_end_date.day;
            if(journey_end_date.day>31||journey_end_date.day<1)
            {
                cout<<"This date is false!!"<<endl;
                goto k3;
            }
            if(journey_end_date.day==31)
            {
                 if(journey_end_date.month==2||journey_end_date.month==4||journey_end_date.month==6||journey_end_date.month==9||journey_end_date.month==11)
                    cout<<"This date is false!!"<<endl;
                    goto k3;
            }
            cout << "The number of passengers is: ";
            cout <<calc_number_of_passenger(journey_start_date,journey_end_date,transport_name,journey_head);
            cout<<endl;
            system("pause");
            system("cls");
            goto her;
        }
    case 6:
        {
            cout <<"Enter the number for vehicle you want to show her journey Record:\n1)Car.\t\t2)Passenger Airliners.\t\t3) Trucks."<<endl;
            cout<<"4)Trucks.\t5)Cargo planes.\t\t\t6)Buses ."<<endl;
            cout<<"Your choice is: ";
            m:
            cin>>r;
            if(r==1)
            transport_name ="Car" ;
            else if(r==2)
            transport_name ="Passenger Airliners" ;
            else if(r==3)
            transport_name ="Trucks" ;
            else if(r==4)
            transport_name ="Cargo planes" ;
            else if(r==5)
            transport_name ="Buses" ;
            else
            {
                cout<<"You are enter the default number!!"<<endl;
                goto m;
            }
            print_info(transport_name,journey_head );
            cout<<endl;
            system("pause");
            system("cls");
            goto her;
        }
    case 7:
        {
            system("cls");
            break;
        }
    default:
        {
            cout<<"Sorry you are enter the default number!!"<<endl;
            cout<<endl;
            system("pause");
            system("cls");
            goto her;
        }
    }
    return 0;
}
