struct ability
{
	float offense;
	float defense;
	float control;
	float reb;
	float efficiency;
	ability(player_avg* p)
	{
		offense = p->pts + p->ast + p->orb;
		defense = p->blk + p->stl + p->drb;
		control = p->stl - p->tov;
		reb = p->trb;
		efficiency = p->pts + p->reb + p->ast + p->stl + p->blk - p->fga + p->fg - p->fta + p->ft;
	}
}


