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

#include "log.h"
#include "command-line.h"
#include "checkpointer.h"
#include "config.h"
#include "string.h"
#include <string>
#include <iostream>
#include <sstream>

NS_LOG_COMPONENT_DEFINE("Checkpointer");

using namespace ns3;

namespace ns3 {

NS_OBJECT_ENSURE_REGISTERED (Checkpointer);

// pre-checkpoint and post-checkpoint hooks not currently used
void pre() {}
void post() {}

void restart() {

  FILE *fh = fopen("restarted", "w");
  fprintf(fh, "Set parameters upon restart\n");

  char *env = getenv("NS3_ARGUMENTS");
  if (env != NULL) {
    std::string env_str(env);
    std::stringstream stream(env_str);
    std::string token;
    int val_index;
    while (std::getline(stream, token, ':'))
    {
      val_index = token.rfind("/");
      std::string key = std::string(token, 0, val_index);
      std::string value = std::string(token, val_index+1);
      fprintf(fh, env);
//  Config::Set("/NodeList/*/DeviceList/0/DataRate", StringValue(env));
      Config::Set(key, StringValue(value));
    }
  }

  fclose(fh);

}

TypeId 
Checkpointer::GetTypeId (void)
{
	static TypeId tid = TypeId ("ns3::Checkpointer").SetParent<Object> ();
	return tid;
}

Checkpointer::Checkpointer() 
{
InstallHooks();

}
Checkpointer::~Checkpointer() {}

void Checkpointer::CheckpointAt(float seconds)
{
  Simulator::Schedule (Seconds (seconds), &Checkpointer::DoCheckpoint, this);
}

void 
Checkpointer::InstallHooks(void)
{
  dmtcp_install_hooks(pre, post, restart);
}

void
Checkpointer::DoCheckpoint(void)
{
	int result = dmtcp_checkpoint();
	// TODO: Check return conditions
	char buf[50];
	sprintf(buf, "checkpoint result: %d", result);
	NS_LOG_INFO (buf);
}



} // namespace ns3

