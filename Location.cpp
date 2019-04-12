//
// Created by ruben on 4/5/19.
//

#include "Location.h"

// Defina los metodos que crea necesario

UTEC::Location::Location():position_id{0},state_code{""},county{""},latitude{0},longitude{0},line{""},construction{""}{};

UTEC::Location::Location(int position_id, std::string state_code, std::string county, double latitude, double longitude,
                   std::string line, std::string construction) {
    Location::position_id=position_id;
    Location::state_code=state_code;
    Location::county=county;
    Location::latitude=latitude;
    Location::longitude=longitude;
    Location::line=line;
    Location::construction=construction;
}

int UTEC::Location::get_position_id(){ return position_id;}

void UTEC::Location::printLocation() {
    std::cout<<"POSITION ID: "<<position_id<<std::endl;
    std::cout<<"State Code: "<<state_code<<std::endl;
    std::cout<<"Country: "<<county<<std::endl;
    std::cout<<"Latitude: "<<latitude<<std::endl;
    std::cout<<"Longitude: "<<longitude<<std::endl;
    std::cout<<"Line: "<<line<<std::endl;
    std::cout<<"Construction: "<<construction<<std::endl;
    std::cout<<std::endl;
}
