<template>
  <el-button type="primary" style="margin-left: 16px" @click="drawer = true">套餐类型</el-button>
  <el-button type="primary" style="margin-left: 16px" @click="drawer2 = true">选检项目</el-button>

  <el-drawer v-model="drawer" title="I am the title" :with-header="false">
    <span>从业套餐选择</span>
    <div class="demo-input-suffix">
    <el-row :gutter="20">
      <span class="suibian"
        >关键字: </span
      >
      <el-input
        v-model="input1"
        class="suibian"
        width="50px"
        placeholder="请输入关键字"
        :suffix-icon="Search"
      />
      <el-button type="primary"  class="suibian" @click="handleSearch">查询</el-button>
      <el-button @click="handleCz" class="suibian">重置</el-button>
    </el-row>
  </div>

  <el-table
    :data="tableData"
    style="width: 100%"
    :row-class-name="tableRowClassName"
  >
    <el-table-column prop="xz" label="XZ" width="180" />
    <el-table-column prop="tcmc" label="TCMC" width="180" />
    <el-table-column prop="tcjp" label="TCJP" />
  </el-table>
  </el-drawer>

  <el-drawer v-model="drawer2" title="I am the title" :with-header="false">
    <span>套餐项目</span>
    <div class="demo-input-suffix">
    <el-row :gutter="20">
      <span class="suibian"
        >关键字: </span
      >
      <el-input
        v-model="input1"
        class="suibian"
        width="50px"
        placeholder="请输入关键字"
        :suffix-icon="Search"
      />
      <el-button type="primary"  class="suibian" @click="handleSearch">查询</el-button>
      <el-button @click="handleCz" class="suibian">重置</el-button>
    </el-row>
  </div>

  <el-table
    :data="tableData"
    style="width: 100%"
    :row-class-name="tableRowClassName"
  >
    <el-table-column prop="xz" label="XZ" width="180" />
    <el-table-column prop="tcmc" label="TCMC" width="180" />
    <el-table-column prop="tcjp" label="TCJP" />
  </el-table>
  </el-drawer>
</template>

<script lang="ts" setup>
import { ref } from 'vue'
import { Calendar, Search } from '@element-plus/icons-vue'
// import { ArrowDown } from '@element-plus/icons-vue'

const drawer = ref(false)
const drawer2 = ref(false)
const input1 = ref('')
// const handleCommand = (command: string | number | object) => {
//   console.log(document.getElementById('keshi'))
//   console.log(command)

// }

const handleSearch = () => {
  console.log('search')
}

const handleCz = () => {
  console.log('Cz')
}

interface User {
  xz: string
  tcmc: string
  tcjp: string
}

const tableRowClassName = ({
  row,
  rowIndex,
}: {
  row: User
  rowIndex: number
}) => {
  if (rowIndex === 1) {
    return 'warning-row'
  } else if (rowIndex === 3) {
    return 'success-row'
  }
  return ''
}

const tableData: User[] = [
  {
    xz: '2016-05-03',
    tcmc: '优惠套餐-ms',
    tcjp: 'YHTC',
  },
  {
    xz: '2016-05-02',
    tcmc: '健康证',
    tcjp: 'CYTJ',
  },
  {
    xz: '2016-05-04',
    tcmc: 'Tom',
    tcjp: 'No. 189, Grove St, Los Angeles',
  },
  {
    xz: '2016-05-01',
    tcmc: 'Tom',
    tcjp: 'No. 189, Grove St, Los Angeles',
  },
]
</script>

<style>
.el-table .warning-row {
  --el-table-tr-bg-color: var(--el-color-warning-light-9);
}
.el-table .success-row {
  --el-table-tr-bg-color: var(--el-color-success-light-9);
}
.suibian{
  display: flex;
      justify-content: space-between;
      align-items: center;
}
</style>