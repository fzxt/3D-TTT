//
//  Channel.cpp
//  COSC4F00_ASSIGN2
//
//  Created by Fahad on 2016-11-10.
//  Copyright © 2016 Fahad. All rights reserved.
//

#include "Channel.hpp"

Channel::Channel() { }

Port<GameEvent, ClientEvent> Channel::asPort1() {
    return Port<GameEvent, ClientEvent>(port1ToPort2);
}

Port<ClientEvent, GameEvent> Channel::asPort2() {
    return Port<ClientEvent, GameEvent>(port2ToPort1);
}
