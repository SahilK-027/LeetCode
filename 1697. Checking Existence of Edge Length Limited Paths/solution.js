/*
374 ms
77.9 MB

TC : O(V + E)
SC : O(V + E)
*/

/**
 * @author : SahilK-027
 * @brief : union find
*/

var distanceLimitedPathsExist = function(n, edgeList, queries) {
    const par = Uint32Array.from({length: n}, (_,i) => i),
    find = x => x === par[x] ? x : par[x] = find(par[x]),
    union = (x,y) => par[find(y)] = find(x)
    let ord = Uint32Array.from({length: queries.length}, (_,i) => i), j = 0
    edgeList.sort((a,b) => a[2] - b[2])
    ord.sort((a,b) => queries[a][2] - queries[b][2])
    for (let i of ord) {
        let [a,b,wt] = queries[i]
        while (edgeList[j]?.[2] < wt)
            union(edgeList[j][0], edgeList[j++][1])
        queries[i] = find(a) === find(b)
    }
    return queries
};