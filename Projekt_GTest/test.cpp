#include "pch.h"
#include "kalkulator.h"
#include "gtest/gtest.h"


//Przetestowanie dodanych funkcji z operacjami algebraicznymi
TEST(KalkulatorTest, Dzielenie) {

    kalkulator kalk;

    EXPECT_EQ(2, kalk.dzielenie(6, 3));
    EXPECT_EQ(0, kalk.dzielenie(0, 5));
    EXPECT_EQ(-100, kalk.dzielenie(5, 0));
}

TEST(KalkulatorTest, Silnia) {

    kalkulator kalk;

    EXPECT_EQ(1, kalk.silnia(0));
    EXPECT_EQ(1, kalk.silnia(1));
    EXPECT_EQ(120, kalk.silnia(5));
}

TEST(KalkulatorTest, Potega) {

    kalkulator kalk;

    EXPECT_DOUBLE_EQ(8, kalk.potêga(2, 3));
    EXPECT_DOUBLE_EQ(1.0 / 8, kalk.potêga(2, -3));
}

TEST(KalkulatorTest, Pierwiastek) {

    kalkulator kalk;

    EXPECT_DOUBLE_EQ(4, kalk.pierwiastek(16, 2));
    EXPECT_TRUE(std::isnan(kalk.pierwiastek(-16, 2)));
    EXPECT_TRUE(std::isnan(kalk.pierwiastek(16, 0)));
    EXPECT_DOUBLE_EQ(3, kalk.pierwiastek(27, 3));
}

//Test konwerterów 
//binarny do decymalnego
TEST(KalkulatorBinTest, BinToDecValidInput) {
    kalkulator_bin kalk_bin;
    EXPECT_EQ(5, kalk_bin.bin_dec(101));  
    EXPECT_EQ(12, kalk_bin.bin_dec(1100));  
}

TEST(KalkulatorBinTest, BinToDecInvalidInput) {
    kalkulator_bin kalk_bin;
    EXPECT_EQ(-3, kalk_bin.bin_dec(1234));  
}
//decymalnego do binarny 
TEST(KalkulatorBinTest, DecToBinValidInput) {
    kalkulator_bin kalk_bin;
    EXPECT_EQ(101, kalk_bin.dec_bin(5));  
    EXPECT_EQ(1100, kalk_bin.dec_bin(12));  
}

TEST(KalkulatorBinTest, DecToBinInvalidInput) {
    kalkulator_bin kalk_bin;
    EXPECT_EQ(-2, kalk_bin.dec_bin(-5));  
}

//oktalny do decymalny
TEST(KalkulatorOCTTest, OctToDecValidInput) {
    kalkulator_octa kalk_oct;

    EXPECT_EQ(45, kalk_oct.oct_dec(55));
    EXPECT_EQ(10, kalk_oct.oct_dec(12));
}

TEST(KalkulatorOCTTest, OctToDecInvalidInput) {
    kalkulator_octa kalk_oct;
    EXPECT_EQ(-3, kalk_oct.oct_dec(999));
}

//decymalnego do oktalny 
TEST(KalkulatorOCTTest, DecToOctValidInput) {
    kalkulator_octa kalk_oct;
    EXPECT_EQ(177, kalk_oct.dec_oct(127));
    EXPECT_EQ(21, kalk_oct.dec_oct(17));
}

TEST(KalkulatorOCTTest, DecToOctInvalidInput) {
    kalkulator_octa kalk_oct;
    EXPECT_EQ(-2, kalk_oct.dec_oct(-5));
}

//heksadecymalny do decymalny 
TEST(KalkulatorHexTest, HexToDecValidInput) {
    kalkulator_hex kalk_hex;
    EXPECT_EQ(13, kalk_hex.hex_dec("D"));
    EXPECT_EQ(3871, kalk_hex.hex_dec("F1F"));
}

TEST(KalkulatorHexTest, HexToDecInvalidInput) {
    kalkulator_hex kalk_hex;
    EXPECT_EQ(-3, kalk_hex.hex_dec("J"));
}

//decymalnego do heksadecymalny 
TEST(KalkulatorHexTest, DecToHexValidInput) {
   kalkulator_hex kalk_hex;
   EXPECT_EQ("3E7", kalk_hex.dec_hex(999));
   EXPECT_EQ("4D", kalk_hex.dec_hex(77));
}

TEST(KalkulatorHexTest, DecToHexInvalidInput) {
   kalkulator_hex kalk_hex;
   EXPECT_EQ("-2", kalk_hex.dec_hex(-5));
}



int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}