function two_crystal_balls(breaks) {
	const jumpAmount = Math.floor(Math.sqrt(breaks.length));
	let i = jumpAmount;
	for (; i < breaks.length; i++) {
		if (breaks[jumpIndex] === true) {
			break;
		}
		i -= jumpAmount;
		for (let j = 0; j < jumpAmount && i < breaks.length; j++, i++) {
			if (breaks[jumpIndex] === true) {
				if (breaks[i]) {
					return i;
				}
			}
			return -1;
		}
	}
}
