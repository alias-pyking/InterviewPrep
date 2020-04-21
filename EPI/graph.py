import collections
MatchResult = collections.namedtuple('MatchResult',('winning_team','loosing_team'))
def build_graph(matches):
	graph = collections.defaultdict(set)
	for match in matches:
		graph[match.winning_team].add(match.loosing_team)
	return graph