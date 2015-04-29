/*****************************************************************/
/*    NAME: Michael Benjamin, Henrik Schmidt, and John Leonard   */
/*    ORGN: Dept of Mechanical Eng / CSAIL, MIT Cambridge MA     */
/*    FILE: BHV_AvoidObstacles.h                                 */
/*    DATE: Aug 2nd 2006                                         */
/*                                                               */
/* This file is part of MOOS-IvP                                 */
/*                                                               */
/* MOOS-IvP is free software: you can redistribute it and/or     */
/* modify it under the terms of the GNU General Public License   */
/* as published by the Free Software Foundation, either version  */
/* 3 of the License, or (at your option) any later version.      */
/*                                                               */
/* MOOS-IvP is distributed in the hope that it will be useful,   */
/* but WITHOUT ANY WARRANTY; without even the implied warranty   */
/* of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See  */
/* the GNU General Public License for more details.              */
/*                                                               */
/* You should have received a copy of the GNU General Public     */
/* License along with MOOS-IvP.  If not, see                     */
/* <http://www.gnu.org/licenses/>.                               */
/*****************************************************************/
 
#ifndef BHV_AVOID_OBSTACLES_X_HEADER
#define BHV_AVOID_OBSTACLES_X_HEADER

#include "IvPBehavior.h"
#include "AOF_AvoidObstaclesX.h"
#include "XYPolygon.h"

class BHV_AvoidObstaclesX : public IvPBehavior {
public:
  BHV_AvoidObstaclesX(IvPDomain);
  ~BHV_AvoidObstaclesX() {delete(m_aof_avoid);};
  
  bool         setParam(std::string, std::string);
  IvPFunction* onRunState();
  void         onIdleState();
  void         onCompleteState()     {postErasablePolygons();};
  void         onSetParamComplete();

 protected:
  bool    handleVisualHints(std::string);
  void    postViewablePolygons();
  void    postErasablePolygons();
  bool    checkForObstacleUpdate();
  void    getRelevance();

protected:
  AOF_AvoidObstaclesX *m_aof_avoid;

  double  m_allowable_ttc;      // Allowable time to collision
  double  m_activation_dist;    // Outside of which no IPF created
  double  m_buffer_dist;        // Between OS and obstacle(s)
  double  m_pheading_influence;

  double  m_pwt_outer_dist;
  double  m_pwt_inner_dist;
  double  m_completed_dist;
 
  std::string  m_obstacle_key;
  std::string  m_obstacle_update_var;

  std:: string m_hint_obst_edge_color;
  std:: string m_hint_obst_vertex_color;
  std:: string m_hint_obst_fill_color;
  double m_hint_obst_fill_transparency;

  std:: string m_hint_buff_edge_color;
  std:: string m_hint_buff_vertex_color;
  std:: string m_hint_buff_fill_color;
  double m_hint_buff_fill_transparency;
};
#endif





