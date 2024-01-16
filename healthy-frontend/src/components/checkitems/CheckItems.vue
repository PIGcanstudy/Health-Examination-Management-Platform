<template>
  <el-button type="primary" style="margin-left: 16px" @click="drawer = true">套餐类型</el-button>
  <el-button type="primary" style="margin-left: 16px" @click="drawer2 = true">选检项目</el-button>

  <el-drawer v-model="drawer" title="I am the title" :with-header="false">
    <span>从业套餐选择</span>
    <el-form :inline="true" :model="formInline" class="demo-form-inline">
    <el-form-item label="关键字" class="bold-label">
      <el-input
        v-model="input1"
        class="suibian"
        width="50px"
        placeholder="请输入关键字"
        :suffix-icon="Search"
      />
    </el-form-item>
    <el-form-item>
      <el-button type="primary" :icon="Search" @click="handleSearch">搜索</el-button>
      <el-button plain @click="handleCz">重置</el-button>
    </el-form-item>
  </el-form>

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
    <el-form :inline="true" :model="formInline" class="demo-form-inline">
    <el-form-item label="关键字" class="bold-label">
      <el-input
        v-model="input2"
        class="suibian"
        width="50px"
        placeholder="请输入关键字"
        :suffix-icon="Search"
      />
    </el-form-item>
    <el-form-item>
      <el-button type="primary" :icon="Search" @click="handleSearch">搜索</el-button>
      <el-button plain @click="handleCz">重置</el-button>
    </el-form-item>
  </el-form>
  </el-drawer>
</template>

<script lang="ts" setup>
import { ref } from 'vue'
import { reactive } from 'vue'
import { Calendar, Search } from '@element-plus/icons-vue'
import { ArrowDown } from '@element-plus/icons-vue'

const formInline = reactive({
  name: '',
  code: '',
  contact: '',
  phone: ''
})
const drawer = ref(false)
const drawer2 = ref(false)
const input1 = ref('')
const input2 = ref('')
// const handleCommand = (command: string | number | object) => {
//   console.log(document.getElementById('keshi'))
//   console.log(command)

// }

const handleSearch = () => {
  alert('search')
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
</style>