/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
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
 */

#include "ns3/core-module.h"
#include "dmtcp.h"

NS_LOG_COMPONENT_DEFINE ("HelloSimulator");

using namespace ns3;

int
main (int argc, char *argv[])
{
	char msg[50];
	for (int i=1; i < 30; i++)
	{
		if (i%10 == 0)
		{
			sprintf(msg, "Checkpointing...");
			NS_LOG_UNCOND (msg);
			int retval = dmtcp_checkpoint();
			sprintf(msg, "Return value: %d", retval);
			NS_LOG_UNCOND (msg);

		}
		else
		{

			sprintf(msg, "Hello simulator %d", i);
			NS_LOG_UNCOND (msg);
		}
		sleep(1);
	}
}
