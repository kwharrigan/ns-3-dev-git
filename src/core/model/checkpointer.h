/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2014 Georgia Tech Research Corporation
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Author: Kyle Harrigan <kwharrigan@gmail.com>
 */

#ifndef CHECKPOINTER_H
#define CHECKPOINTER_H

#include "object.h"
#include "simulator.h"
#include "dmtcp.h"

namespace ns3 {

class Checkpointer : public Object
{

public:
	static TypeId GetTypeId (void);

	Checkpointer ();
	virtual ~Checkpointer ();
	void DoCheckpoint();
	void CheckpointAt(float seconds);
private:
	void InstallHooks();
}; 

} // namespace ns3

#endif
