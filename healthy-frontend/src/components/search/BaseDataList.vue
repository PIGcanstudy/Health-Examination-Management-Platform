<template>
  <div class="form">
    <Search :sendToSearch="getToSearch" :sendToReset="getToReset"></Search>
    <!-- <div class="top">
      <div class="form-item">
        <label for="id" style="width: 70px">单位名称</label>
        <el-input id="id" placeholder="请输入" style="margin-left: 10px; width: 120px" />
      </div>
      <div class="form-item">
        <label for="name" style="width: 70px">信用代码</label>
        <el-input id="name" placeholder="请输入" style="margin-left: 10px; width: 120px"></el-input>
      </div>
      <div class="form-item">
        <label for="jp" style="width: 70px">联系人</label>
        <el-input id="jp" placeholder="请输入" style="margin-left: 10px; width: 120px"></el-input>
      </div>
      <div class="form-item">
        <label for="jp" style="width: 70px">联系电话</label>
        <el-input id="jp" placeholder="请输入" style="margin-left: 10px; width: 120px"></el-input>
      </div>
      <div class="form-item">
        <el-row>
          <el-button type="primary">搜索</el-button>
          <el-button type="plain">重置</el-button>
        </el-row>
      </div>
    </div> -->
    <div class="option">
      <el-row>
        <el-button type="primary">新增</el-button>
        <el-button type="plain">更多操作</el-button>
        <el-button type="plain">关闭搜索</el-button>
        <el-button type="plain">关闭提示</el-button>
      </el-row>
    </div>
    <div class="style">
      <span class="message">
        已选择
        <span class="count">0</span>
        项
        <a class="clear">清空</a>
      </span>
    </div>
    <div class="table">
      <el-table :data="changingTableData" style="width: 100%">
        <!-- <el-table-column fixed prop="date" label="Date" width="150" /> -->
        <el-table-column prop="name" label="单位名称" width="160" />
        <el-table-column prop="credit" label="信用代码" width="120" />
        <el-table-column prop="examination" label="体检类型" width="120" />
        <el-table-column prop="address" label="所属地区" width="120" />
        <el-table-column prop="category" label="行业类别" width="120" />
        <el-table-column prop="etype" label="经济类型" width="120" />
        <el-table-column prop="scale" label="企业规模" width="120" />
        <el-table-column prop="contact" label="联系人" width="120" />
        <el-table-column prop="phone" label="联系电话" width="120" />
        <el-table-column fixed="right" label="操作" width="120">
          <template #default>
            <el-button link type="primary" size="small" @click="handleClick">查看</el-button>
            <el-button link type="primary" size="small">更多操作</el-button>
          </template>
        </el-table-column>
      </el-table>
    </div>
  </div>
</template>

<script setup>
import { ref, reactive } from 'vue'
import Search from '@/components/search/Search.vue'

const value = ref('')

const options = [
  {
    value: '职业体检',
    label: '职业体检'
  },
  {
    value: '健康体检',
    label: '健康体检'
  },
  {
    value: '放射体检',
    label: '放射体检'
  },
  {
    value: '从业体检',
    label: '从业体检'
  }
]

const handleClick = () => {
  console.log('click')
}

const tableData = [
  {
    name: '乐山市峨边盛和矿业',
    credit: '--',
    examination: '健康体检',
    address: '--',
    category: '铁矿采选*',
    etype: '国有企业',
    scale: '--',
    contact: '--',
    phone: '--'
  },
  {
    name: '习水宏旭纸箱有限公司',
    credit: '--',
    examination: '健康体检',
    address: '--',
    category: '--',
    etype: '--',
    scale: '--',
    contact: '--',
    phone: '--'
  },
  {
    name: '四川峨边三丰冶金材料',
    credit: '--',
    examination: '健康体检',
    address: '--',
    category: '--',
    etype: '国有企业',
    scale: '--',
    contact: '--',
    phone: '--'
  }
]

/**
 * inter changes below
 */

/**
 * 响应式数据，以便随时刷新表格
 */
let changingTableData = ref(tableData)

/**
 * 得到要搜索的内容
 * 支持模糊搜索
 * @param {*} value
 */
function getToSearch(value) {
  changingTableData.value = []
  // 遍历当前数据，进行比较
  for()
  for (let i in tableData) {
    // let flag = 0
    // // 遍历 name
    // let pname = 0
    // while (pname < tableData[i].name.length) {
    //   let len = value.name.trim().length
    //   let data = tableData[i].name.slice(pname, pname + len)
    //   console.log(data)
    //   if (data === value.name) {
    //     console.log('姓名匹配！')
    //     flag++
    //     break
    //   }
    //   pname++
    // }
    // let pcredit = 0
    // while (pcredit < tableData[i].credit.length) {
    //   let len = value.credit.trim().length
    //   let data = tableData[i].credit.slice(pcredit, pcredit + len)
    //   console.log(data)
    //   if (data === value.credit) {
    //     console.log('信用代码匹配！')
    //     flag++
    //     break
    //   }
    // }
    // let pcontact = 0
    // while (pcontact < tableData[i].contact.length) {
    //   let len = value.contact.trim().length
    //   let data = tableData[i].contact.slice(pcontact, pcontact + len)
    //   console.log(data)
    //   if (data === value.contact) {
    //     console.log('联系人匹配！')
    //     flag++
    //     break
    //   }
    // }

    // let pphone = 0
    // while (pphone < tableData[i].phone.length) {
    //   let len = value.phone.trim().length
    //   let data = tableData[i].phone.slice(pphone, pphone + len)
    //   console.log(data)
    //   if (data === value.phone) {
    //     console.log('电话匹配！')
    //     flag++
    //     break
    //   }
    // }

    // if (flag === 4) {
    //   changingTableData.value.push(tableData[i])
    // }

    // test
    let flag = 0
    for (let x in value, let y in tableData[i]) {
      let p = 0
      while (p < y.length) {
        let len = x.trim().length
        let data = y.slice(p, p + len)
        console.log(data)
        if(data === x) {
          console.log('匹配')
          flag++
          break
        }
      }
    }
    if (flag === 4) {
      changingTableData.value.push(tableData[i])
    }
  }
}

function getToReset() {
  changingTableData.value = tableData
}
</script>

<style lang="scss" scoped>
.top {
  display: flex;
  height: 50px;
  border-bottom: 2px dashed rgb(224, 224, 238);

  .form-item {
    margin-left: 5px;
  }
}

.option {
  margin-top: 20px;
}

.style {
  height: 33px;
  margin-top: 20px;
  background-color: rgb(240, 250, 255);
  line-height: 33px;
  border: 1px solid rgb(171, 220, 255);
}

.table {
  margin-top: 20px;
  text-align: center;
}
</style>
