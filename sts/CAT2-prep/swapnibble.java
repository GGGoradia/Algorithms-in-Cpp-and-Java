public class swapnibble {//done
    public static byte swap(byte x){
        byte left=(byte)((x & 0xF0)>>4);
        byte right=(byte)((x & 0x0F));
        return (byte)((right<<4)|left);
    }
    public static void main(String []args){
        byte og=(byte) 0b10001010;
        byte swapped=swap(og);
        System.out.println(Integer.toBinaryString(swapped & 0xFF ));
    }
}
