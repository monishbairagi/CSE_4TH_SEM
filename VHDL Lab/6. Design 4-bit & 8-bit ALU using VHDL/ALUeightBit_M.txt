----------------------------------------------------------------------------------
-- Engineer:	    Monish Kumar Bairagi
-- Project Name:    ALUeightBit
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity ALUeightBit is
	Port(
		a : in STD_LOGIC_VECTOR(7 downto 0);
		b : in STD_LOGIC_VECTOR(7 downto 0);
		sel : in STD_LOGIC_VECTOR(3 downto 0);
		alu_out : out STD_LOGIC_VECTOR(7 downto 0)
	    );
end ALUeightBit;

architecture Behavioral of ALUeightBit is
begin
process(sel,a,b)
begin
	case sel is
		when "0000" => alu_out <= a + b;
		when "0001" => alu_out <= a and b;
		when "0010" => alu_out <= not b;
		when "0110" => alu_out <= not a;
		when "0111" => alu_out <= a xor b;
		when "1001" => alu_out <= a xnor b;
		when "1011" => alu_out <= (not a) + 1;
		when "1100" => alu_out <= (not b) + 1;
		when "1110" => alu_out <= a or b;
		when "1111" => alu_out <= a nand b;
		when others => alu_out <= "XXXXXXXX";
	end case;
end process;
end Behavioral;