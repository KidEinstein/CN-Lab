import java.util.BitSet;


public class Crc {
	static BitSet divisorBitSet = BitSet.valueOf(new long[]{0b10001000000100001});
	
	public static BitSet getRemainder(long dataWord) {
		BitSet dataWordBitSet = BitSet.valueOf(new long[]{dataWord * (long)Math.pow(2, 16)});
		return getRemainder(dataWordBitSet);
	}
	public static BitSet getRemainder(BitSet dataWordBitSet) {
		System.out.println(dataWordBitSet.toString());
		for (int i = dataWordBitSet.length(); i >= 17; i--) {
			BitSet dividend = dataWordBitSet.get(i - 17, i);
			System.out.println("Dividend :" + dividend.toString());
			System.out.println("Divisor :" + divisorBitSet.toString());

			if (dividend.get(16)) {
				dividend.xor(divisorBitSet);
				for (int j = 0, k = i - 17 ; j < 17; j++, k++) {
					if (dividend.get(j)) {
						dataWordBitSet.set(k, true);
					}
					else {
						dataWordBitSet.set(k, false);
					}
				}
			}
			System.out.println("Result :" + dividend.toString());
		}
		System.out.println(dataWordBitSet.get(0, 16).toString());
		return dataWordBitSet;
	}
	
	public static BitSet getCodeWord(long dataWord) {
		BitSet codeWordBitSet = BitSet.valueOf(new long[]{dataWord * (long)Math.pow(2, 16)});
		BitSet remainder = getRemainder(dataWord);
		for (int i = 0; i < 16; i++) {
			codeWordBitSet.set(i, remainder.get(i));
		}
		return codeWordBitSet;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Crc.getRemainder(0b1011);
		System.out.println(Crc.getCodeWord(0b1011));
	}

}
