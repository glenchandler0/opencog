/*
 * AFImportanceDiffusionAgent.h
 *
 * Copyright (C) 2016 Opencog Foundation
 * 
 * All Rights Reserved
 *
 * Written by Misgana Bayetta <misgana.bayetta@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License v3 as
 * published by the Free Software Foundation and including the exceptions
 * at http://opencog.org/wiki/Licenses
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program; if not, write to:
 * Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef AFIMPORTANCEDIFFUSIONAGENT_H
#define AFIMPORTANCEDIFFUSIONAGENT_H

//#include <chrono>

#include "ImportanceDiffusionBase.h"
#include "DiffusionStat.h"

namespace opencog
{
/** \addtogroup grp_attention
 *  @{
 */
using namespace opencog::ecan;
    
class CogServer;

/** Diffuses short term importance between atoms in the attentional focus.
 *
 * Diffusion sources consist of all atoms that are in the attentional focus.
 * 
 * Supports two types of importance diffusion:
 * 
 * (1) Diffusion to atoms that are incident to each atom, consisting of that 
 *     atom's incoming and outgoing sets (excluding hebbian links)
 * 
 * (2) Diffusion to atoms that are adjacent to each atom, where the type of
 *     the connecting edge is a hebbian link
 * 
 * Please refer to the detailed description of this agent in the README file,
 * where an extensive explanation of the algorithm, features and pending
 * work is explained.
 */
class AFImportanceDiffusionAgent : public Agent, public ImportanceDiffusionBase
{
  
private:
    HandleSeq diffusionSourceVector();
    
    std::chrono::time_point<hr_clock> last_spreading_time;
    bool first_time = true;
    
    void spreadImportance();
    void diffuseAtom(Handle source);
    
public:
     AFImportanceDiffusionAgent(CogServer&);
    ~AFImportanceDiffusionAgent();
    
    virtual void run();
    virtual const ClassInfo& classinfo() const { return info(); }
    static const ClassInfo& info() {
    static const ClassInfo _ci("opencog::AFImportanceDiffusionAgent");
        return _ci;
    }
};

/** @}*/
} // namespace



#endif /* AFIMPORTANCEDIFFUSIONAGENT_H */

