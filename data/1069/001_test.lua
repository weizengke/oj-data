local a={}
local i=1
local k
-- 从文件中读取数据，跳过为"#"的那一行，存入table中
for line in io.lines("data2.in") do
	if( line~="#" ) then
		a[i]=line
		i=i+1
	else
		k=i
	end
end
-- 判断指令字符串中是否有“=”，没有则结束程序
local h
h=string.find(a[k],"=")
if( h==nil ) then
	io.open("data2.out","a+"):write("Wrong!\n")
	return
end
-- 获取“=”两边的字符串
local l
local r
l=string.sub(a[k],1,h-1)
r=string.sub(a[k],h+1,string.len(a[k]))

-- 检测指令是否合法
local ch={{},{},{}}
for j=1,k-1 do

	for w,v,z in string.gmatch(a[j],"(%a*)%s(%a*)%((%d*)%)") do
		ch[j][1]=w  --第一个空格前的单词
		ch[j][2]=v  --夹在第一个空格以及反括号前的单词
		ch[j][3]=z  --括号中的单词
		if( w==nil or z==nil ) then
			io.open("data2.out","a+"):write("Wrong!\n")
			return
		end
		if( v~="int" and v~="char" ) then
			io.open("data2.out","a+"):write("Wrong!\n")
			return
		end
		--如果指令左边的单词和w匹配
		if( w==l ) then
			if( v=="char" ) then
				--第一个字符和最后一个字符不是引号则结束程序
				if( string.sub(r,1,1)~="\"" and string.sub(r,string.len(r),string.len(r))~="\"" ) then
					io.open("data2.out","a+"):write("Wrong!\n")
					return
				end
				--双引号中间还有引号则结束程序
				if( string.match(string.sub(r,2,string.len(r)-1),"\"") ~=nil ) then
					io.open("data2.out","a+"):write("Wrong!\n")
					return
				end
				--如果没有匹配双引号的单词则结束程序
				--若果有则取出双引号中的单词
				r=string.match(r,"\"(%a*)\"")
				if( r== nil ) then
					io.open("data2.out","a+"):write("Wrong!\n")
					return
				end
				--判断长度是否合法
				if( string.len(r)<=tonumber(z) ) then
					io.open("data2.out","a+"):write("Right!\n")
					return
				else
					io.open("data2.out","a+"):write("Wrong!\n")
					return
				end

			-- v=="int"时
			else
				--有非数字字符存在则结束程序
				if( string.match(r,"%D")~=null ) then
					io.open("data2.out","a+"):write("Wrong!\n")
					return
				end
				if( string.len(r)<=tonumber(z) ) then
					io.open("data2.out","a+"):write("Right!\n")
					return
				else
					io.open("data2.out","a+"):write("Wrong!\n")
					return
				end
			end

		end

	end

end

--如果找不到与指令左边的单词相匹配的项则结束程序

io.open("data2.out","a+"):write("Wrong!\n")
return
