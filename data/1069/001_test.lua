local a={}
local i=1
local k
-- ���ļ��ж�ȡ���ݣ�����Ϊ"#"����һ�У�����table��
for line in io.lines("data2.in") do
	if( line~="#" ) then
		a[i]=line
		i=i+1
	else
		k=i
	end
end
-- �ж�ָ���ַ������Ƿ��С�=����û�����������
local h
h=string.find(a[k],"=")
if( h==nil ) then
	io.open("data2.out","a+"):write("Wrong!\n")
	return
end
-- ��ȡ��=�����ߵ��ַ���
local l
local r
l=string.sub(a[k],1,h-1)
r=string.sub(a[k],h+1,string.len(a[k]))

-- ���ָ���Ƿ�Ϸ�
local ch={{},{},{}}
for j=1,k-1 do

	for w,v,z in string.gmatch(a[j],"(%a*)%s(%a*)%((%d*)%)") do
		ch[j][1]=w  --��һ���ո�ǰ�ĵ���
		ch[j][2]=v  --���ڵ�һ���ո��Լ�������ǰ�ĵ���
		ch[j][3]=z  --�����еĵ���
		if( w==nil or z==nil ) then
			io.open("data2.out","a+"):write("Wrong!\n")
			return
		end
		if( v~="int" and v~="char" ) then
			io.open("data2.out","a+"):write("Wrong!\n")
			return
		end
		--���ָ����ߵĵ��ʺ�wƥ��
		if( w==l ) then
			if( v=="char" ) then
				--��һ���ַ������һ���ַ������������������
				if( string.sub(r,1,1)~="\"" and string.sub(r,string.len(r),string.len(r))~="\"" ) then
					io.open("data2.out","a+"):write("Wrong!\n")
					return
				end
				--˫�����м仹���������������
				if( string.match(string.sub(r,2,string.len(r)-1),"\"") ~=nil ) then
					io.open("data2.out","a+"):write("Wrong!\n")
					return
				end
				--���û��ƥ��˫���ŵĵ������������
				--��������ȡ��˫�����еĵ���
				r=string.match(r,"\"(%a*)\"")
				if( r== nil ) then
					io.open("data2.out","a+"):write("Wrong!\n")
					return
				end
				--�жϳ����Ƿ�Ϸ�
				if( string.len(r)<=tonumber(z) ) then
					io.open("data2.out","a+"):write("Right!\n")
					return
				else
					io.open("data2.out","a+"):write("Wrong!\n")
					return
				end

			-- v=="int"ʱ
			else
				--�з������ַ��������������
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

--����Ҳ�����ָ����ߵĵ�����ƥ��������������

io.open("data2.out","a+"):write("Wrong!\n")
return
