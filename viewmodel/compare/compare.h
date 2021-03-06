#ifndef COMPARE_H
#define COMPARE_H


#include "../../common/dataType.h"
#include "../../common/common.h"
namespace PlayerCompare
{
    static bool cmp_g(player_avg* a, player_avg* b){return a->g > b->g;}
    static bool cmp_gs(player_avg* a, player_avg* b){return a->gs > b->gs;}
    static bool cmp_mp(player_avg* a, player_avg* b){return a->mp > b->mp;}
    static bool cmp_fgper(player_avg* a, player_avg* b){return a->fgper > b->fgper;}
    static bool cmp_fg(player_avg* a, player_avg* b){return a->fg > b->fg;}
    static bool cmp_fga(player_avg* a, player_avg* b){return a->fga > b->fga;}
    static bool cmp_threepper(player_avg* a, player_avg* b){return a->threepper > b->threepper;}
    static bool cmp_threep(player_avg* a, player_avg* b){return a->threep > b->threep;}
    static bool cmp_threepa(player_avg* a, player_avg* b){return a->threepa > b->threepa;}
    static bool cmp_ftper(player_avg* a, player_avg* b){return a->ftper > b->ftper;}
    static bool cmp_ft(player_avg* a, player_avg* b){return a->ft > b->ft;}
    static bool cmp_fta(player_avg* a, player_avg* b){return a->fta > b->fta;}
    static bool cmp_ts(player_avg* a, player_avg* b){return a->ts > b->ts;}
    static bool cmp_trb(player_avg* a, player_avg* b){return a->trb > b->trb;}
    static bool cmp_orb(player_avg* a, player_avg* b){return a->orb > b->orb;}
    static bool cmp_drb(player_avg* a, player_avg* b){return a->drb > b->drb;}
    static bool cmp_ast(player_avg* a, player_avg* b){return a->ast > b->ast;}
    static bool cmp_stl(player_avg* a, player_avg* b){return a->stl > b->stl;}
    static bool cmp_blk(player_avg* a, player_avg* b){return a->blk > b->blk;}
    static bool cmp_tov(player_avg* a, player_avg* b){return a->tov > b->tov;}
    static bool cmp_pf(player_avg* a, player_avg* b){return a->pf > b->pf;}
    static bool cmp_pts(player_avg* a, player_avg* b){return a->pts > b->pts;}
    static bool cmp_w(player_avg* a, player_avg* b){return a->w > b->w;}
    static bool cmp_l(player_avg* a, player_avg* b){return a->l > b->l;}
}
namespace TeamCompare
{
    static bool cmp_g(team_avg* a, team_avg* b){return a->g > b->g;}
    static bool cmp_wg(team_avg* a, team_avg* b){return a->wg > b->wg;}
    static bool cmp_lg(team_avg* a, team_avg* b){return a->lg > b->lg;}
    static bool cmp_fgper(team_avg* a, team_avg* b){return a->fgper > b->fgper;}
    static bool cmp_fg(team_avg* a, team_avg* b){return a->fg > b->fg;}
    static bool cmp_fga(team_avg* a, team_avg* b){return a->fga > b->fga;}
    static bool cmp_threepper(team_avg* a, team_avg* b){return a->threepper > b->threepper;}
    static bool cmp_threep(team_avg* a, team_avg* b){return a->threep > b->threep;}
    static bool cmp_threepa(team_avg* a, team_avg* b){return a->threepa > b->threepa;}
    static bool cmp_ftper(team_avg* a, team_avg* b){return a->ftper > b->ftper;}
    static bool cmp_ft(team_avg* a, team_avg* b){return a->ft > b->ft;}
    static bool cmp_fta(team_avg* a, team_avg* b){return a->fta > b->fta;}
    static bool cmp_ts(team_avg* a, team_avg* b){return a->ts > b->ts;}
    static bool cmp_trb(team_avg* a, team_avg* b){return a->trb > b->trb;}
    static bool cmp_orb(team_avg* a, team_avg* b){return a->orb > b->orb;}
    static bool cmp_drb(team_avg* a, team_avg* b){return a->drb > b->drb;}
    static bool cmp_ast(team_avg* a, team_avg* b){return a->ast > b->ast;}
    static bool cmp_stl(team_avg* a, team_avg* b){return a->stl > b->stl;}
    static bool cmp_blk(team_avg* a, team_avg* b){return a->blk > b->blk;}
    static bool cmp_tov(team_avg* a, team_avg* b){return a->tov > b->tov;}
    static bool cmp_pf(team_avg* a, team_avg* b){return a->pf > b->pf;}
    static bool cmp_pts(team_avg* a, team_avg* b){return a->pts > b->pts;}
}

#endif
