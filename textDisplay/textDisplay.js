function textDisplay(keycodes) {
    var k = keycodes, t = new Array(), j = 0, s = {32: " ", 186:";", 188:",", 190:".", 222:"'"},
        f = {8:"j > 0 && t.splice(j---1, 1)", 35:"j = l", 36:"j = 0", 37:"j > 0 && j--", 39:"j < l && j++", 46:"j < l && t.splice(j, 1)"}, l = 0, x = 0
    for (let i in k) {
        l = t.length
        x = k[i]
        x in f ? eval(f[x]) : x in s ? t.splice(j++, 0 , s[x]) : t.splice(j++, 0, String.fromCharCode(x).toLowerCase())
        //k[i] == 37 ? j > 0 && j-- : (
        //	k[i] == 39 ? j < l && j++ : (
        //    	k[i] == 8 ? j > 0 && t.splice(j---1, 1) : (
        //            	k[i] == 46 ? j < l && t.splice(j, 1) : (
        //        		k[i] == 36 ? j = 0 : (
        //            		k[i] == 35 ? j = l : (
        //                		k[i] in s ? t.splice(j++, 0 , s[k[i]]) : t.splice(j++, 0, String.fromCharCode(k[i]).toLowerCase())
        //                	)
        //            	)
        //        	)
        //    	)
        //    )
        //)
    }
    return t.join("")
}
