//
//  Channel.hpp
//  COSC4F00_ASSIGN2
//
//  Created by Fahad on 2016-11-10.
//  Copyright © 2016 Fahad. All rights reserved.
//

#ifndef Channel_hpp
#define Channel_hpp

#include <stdio.h>
#include "ClientEvent.hpp"
#include "GameEvent.hpp"

#include "Port.hpp"

class Channel {
private:
    Queue<GameEvent> port1ToPort2 = Queue<GameEvent>();
    Queue<ClientEvent> port2ToPort1 = Queue<ClientEvent>();
public:
    Channel();
    Port<GameEvent, ClientEvent> asPort1();
    Port<ClientEvent, GameEvent> asPort2();
};

#endif /* Channel_hpp */
