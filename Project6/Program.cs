using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            chain[] blockchain;
            blockchain = new chain[10];
            for (int i = 0; i < 10; i++)
            {
                blockchain[i] = new chain();
            }
            blockchain[0].createblock(1, "");
            blockchain[1].createblock(2, blockchain[0].hash);
            blockchain[2].createblock(3, blockchain[1].hash);
            blockchain[3].createblock(1, blockchain[2].hash);
            blockchain[4].createblock(2, blockchain[3].hash);

            if (verifyBC(blockchain))
                Console.WriteLine("блокчейн не нарушен");
            else
                Console.WriteLine("блокчейн нарушен");
            Console.ReadLine();
        }

        static bool verifyBC(chain[] blockchain)
        {
            for (int i = 1; i < chain.count; i++)
            {
                if (blockchain[i].hash != blockchain[i].getHash())
                {
                    return false;
                }
                if (blockchain[i].prevhash != blockchain[i - 1].hash)
                {
                    return false;

                }
            }

            return true;
        }
    }


        class chain
    {
        public double amount;
        public string hash;
        public string prevhash;
        public int index;
        static public int count = 0;
        public string getHash()
        {
            MD5 md5Hash = MD5.Create();
            return GetMd5Hash(md5Hash, amount.ToString() + prevhash.ToString() + index.ToString());


        }
        public void createblock(double a, string ph)
        {
            amount = a;
            prevhash = ph;
            index = count;
            count++;
            hash = getHash();

        }
        static string GetMd5Hash (MD5 md5Hash, string input)
        {
            byte[] data = md5Hash.ComputeHash(Encoding.UTF8.GetBytes(input));
            StringBuilder sBuilder = new StringBuilder();
            for (int i = 0; i < data.Length; i++)
            {
                sBuilder.Append(data[i].ToString("x2"));
            }

            return sBuilder.ToString();
        }




    }
          


        }
          

    
